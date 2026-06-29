# ⚠️ Known Vulnerabilities & Design Limitations

AURIX is an experimental system designed for research and exploration purposes.  
The current implementation includes several structural, security, and architectural limitations, which are documented here for transparency and future improvement.

---

## 🔥 1. Prompt Injection & Memory Poisoning Risk

### Issue
Retrieved memory is directly injected into the LLM prompt without validation, filtering, or trust scoring.

```cpp
"Relevant memory:\n" + memory + "\nUser: " + input
```

### Impact

- Historical inputs can directly influence model behavior
- Retrieved memory is treated as fully trusted context
- No distinction between reliable, irrelevant, or malicious data

## Risk

Since memory is not sanitized or ranked, adversarial or misleading entries can distort model outputs through prompt injection.

## 🧠 2. Pseudo-RAG Retrieval (Keyword-Based Matching Only)

### Issue
The retrieval system relies on simple substring matching:
`if (line.find(keyword) != std::string::npos)`

### Limitations
- No semantic understanding of queries
- No embedding-based similarity search
- No ranking or relevance scoring mechanism

### Impact
Context retrieval is based on surface-level keyword overlap rather than meaning, which can lead to irrelevant or misleading context injection.

---

## 📉 3. Hallucination Amplification via Noisy Context

### Issue
All retrieved memory entries are appended equally without prioritization or filtering.

### Impact
- Low-quality or irrelevant memories may influence output
- Conflicting information is not resolved or normalized
- The model may treat noisy context as factual grounding

### Result
Instead of improving accuracy, retrieval can unintentionally increase hallucination probability.

---

## 🧾 4. Unstructured Memory Storage

### Issue
Memory is stored as a plain text log:

user: ...
ai: ...
----
### Limitations
- No structured schema or metadata
- No timestamps, importance scoring, or topic grouping
- No deduplication or compression strategy

### Impact
As memory grows, irrelevant or outdated information accumulates and degrades retrieval quality over time.

---

## ⚙️ 5. Linear-Time Retrieval (O(n))

### Issue
Each query scans the entire history.txt file sequentially.

### Impact
- Performance degrades as conversation history grows
- Not scalable beyond small datasets
- Latency increases linearly with memory size

---

## 🧨 6. Unsafe External Process Execution

### Issue
LLM inference is executed via _popen with shell redirection:
`_popen("ollama run gemma2:2b < temp_prompt.txt", "r");`

### Risks
- Reliance on external process execution
- File-based prompt construction increases attack surface
- Temporary file handling introduces potential manipulation risks

### Impact
This design introduces avoidable security risks in environments where input cannot be fully trusted.

---

## 📦 7. No Input Sanitization Layer

### Issue
User input is directly embedded into the prompt without filtering or normalization.

### Impact
- Prompt injection attacks are possible
- System-level instructions can be overridden
- Memory content can be exploited through crafted inputs

---

## 🌐 8. No Isolation Between System, Memory, and User Context

### Issue
System prompt, retrieved memory, and user input are concatenated without explicit separation or hierarchy enforcement.

### Impact
- The model may fail to distinguish instruction priority levels
- Increased vulnerability to instruction override attacks
- Reduced robustness against adversarial prompting

---

## 📌 Summary

AURIX prioritizes simplicity and experimental flexibility over production-grade safety and robustness.

Key structural limitations include:
- Absence of semantic retrieval mechanisms
- Lack of memory validation, ranking, or scoring
- No clear isolation between trusted and untrusted context
- File-based execution pipeline with minimal security controls

This system is strictly intended for experimental research and is not suitable for production deployment.
