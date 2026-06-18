#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <vector>

#define C_AI     "\033[1;36m"
#define C_USER   "\033[1;33m"
#define C_BORDER "\033[38;5;240m"
#define C_SYS    "\033[1;90m"
#define C_RESET  "\033[0m"

const std::string PROJECT = "AURIX";

// ---------------------------
// RAG KEYWORDS
// ---------------------------
std::vector<std::string> extract_keywords(const std::string& input) {
    std::vector<std::string> words;
    std::stringstream ss(input);
    std::string w;

    while (ss >> w) {
        if (w.size() > 1)
            words.push_back(w);
    }
    return words;
}

// ---------------------------
// RAG idea
// ---------------------------
std::string retrieve_context(const std::string& input) {
    std::ifstream file("history.txt");
    if (!file.is_open()) return "";

    std::vector<std::string> keywords = extract_keywords(input);

    std::string line;
    std::string context;
    int count = 0;

    while (std::getline(file, line)) {

        if (line.find("----") != std::string::npos) continue;
        if (line.find("user:") != 0) continue; 

        for (auto& k : keywords) {
            if (line.find(k) != std::string::npos) {
                context += line + "\n";
                count++;
                break;
            }
        }

        if (count >= 10) break;
    }

    return context;
}

// ---------------------------
// memory save
// ---------------------------
void log_history(const std::string& user, const std::string& ai) {
    std::ofstream file("history.txt", std::ios::app);
    if (!file.is_open()) return;

    file << "user: " << user << "\n";
    file << "ai: " << ai << "\n";
    file << "----\n";
}

// ---------------------------
// UI
// ---------------------------
void draw_interface(const std::string& status) {
    std::cout << C_AI
        << "\n :: AURIX CORE SYSTEM ::\n"
        << C_RESET;

    std::cout << C_BORDER
        << "============================================================\n"
        << C_RESET;

    std::cout << " STATUS: "
        << (status == "IDLE" ? C_AI : "\033[1;31m")
        << status << C_RESET << "\n";

    std::cout << C_BORDER
        << "============================================================\n"
        << C_RESET;
}

// ---------------------------
// ollama
// ---------------------------
std::string run_ollama(const std::string& prompt) {
    std::ofstream temp("temp_prompt.txt");
    temp << prompt;
    temp.close();

    FILE* pipe = _popen("ollama run gemma2:2b < temp_prompt.txt", "r");
    if (!pipe) return "PIPE ERROR";

    char buffer[512];
    std::string response;

    while (fgets(buffer, sizeof(buffer), pipe)) {
        response += buffer;
    }

    _pclose(pipe);
    return response;
}

// ---------------------------
// MAIN
// ---------------------------
int main() {
    SetConsoleTitleA("AURIX CORE");
    SetConsoleOutputCP(CP_UTF8);

    system("cls");
    draw_interface("IDLE");

    while (true) {
        std::cout << "\n" << C_USER << "user: " << C_RESET;

        std::string input;
        std::getline(std::cin, input);

        if (input == "exit") break;
        if (input == "cls") {
            system("cls");
            draw_interface("IDLE");
            continue;
        }
        if (input.empty()) continue;

        std::cout << C_SYS << "thinking..." << C_RESET << "\r";

        std::string memory = retrieve_context(input);

        std::string prompt =
            "You are AURIX.\n"
            "You are concise, direct, and helpful.\n"
            "Do NOT over-explain.\n\n"
            "Relevant memory:\n" +
            memory +
            "\nUser: " + input +
            "\nAURIX: ";

        std::string response = run_ollama(prompt);

        log_history(input, response);

        std::cout << std::string(40, ' ') << "\r";
        std::cout << C_AI << "AURIX: " << C_RESET << response << "\n";
        std::cout << C_BORDER << "------------------------------------------------------------\n" << C_RESET;
    }

    return 0;
}
