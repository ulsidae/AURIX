# 🚀 AURIX

«Privacy-first AI Productivity Coach powered by Local LLMs»

AURIX is an AI-powered productivity system that evolved from a simple Todo application through real user feedback and iterative product validation.

Instead of using AI just for the sake of it, the product focuses on solving real usability problems discovered through user testing and behavioral analysis.


---


# 🧭 Product Evolution

AURIX did not start as an AI product.
It started as a simple Todo Dashboard built to answer one question:
> “Would anyone actually want to use this?”

That initial version led to structured user validation, which revealed a deeper problem:
Users don’t just want to manage tasks.  
They want to improve how they work.
This insight became the foundation of AURIX.

---

# 📊 Initial Research: Todo Dashboard

📓 [Original Todo Dashboard](https://github.com/ulsidae/dev_logs/tree/main/Frontend%26Client-side/Todo%20Dashboard)

📊 [feedback](https://github.com/ulsidae/RSVP-systems/tree/main/%F0%9F%8C%8DFocusBoard%20User-Validation)


## 🎯 Why I Conducted User Research

While reviewing my previous projects, I noticed a recurring pattern:

- Implementation-heavy development with little validation

- Lack of real user feedback loops

- Projects ending after the first working version

I wanted to shift from:
> “Can I build it?”
to:
> “Would someone actually want to use it?”
So I built a lightweight Todo Dashboard and conducted early-stage user testing.

---

## 🔍 Approach

The study focused on four questions:
1. Is the interface intuitive?
2. Is the workflow frictionless?
3. What problems do users encounter?
4. What features do users naturally request?

**Methodology:**

- 3 users participated in usability testing

- Feedback included both positive and negative responses

- Goal: identify structural usability issues, not polish

---
## 🛠 Implementation

The Todo Dashboard was intentionally minimal.

### 📊 Task Structure
- Daily Routines
- Today's Tasks
- Long-Term Goals
→ Designed to reduce cognitive load across time horizons

---

### ⚡ Local-first Design
- Vanilla JavaScript
- LocalStorage
- Fully offline
→ Fast, lightweight, dependency-free experience

---

### ✨ Simple Workflow
`Create Task → Complete Task → Remove Task`
→ Optimized for low friction execution

---

## 📊 User Feedback Summary

| Category | Positive | Neutral | Negative |
| :--- | :--- | :--- | :--- |
| First Impression | 66.7% | 0 | 33.3% |
| Ease of Use | 66.7% | 33.3% | 0 |
| UI / Design | 66.7% | 0 | 33.3% |
| Performance | 100% | 0 | 0 |
| Willingness to Use | 66.7% | 33.3% | 0 |

**User Ratings:**
- User A: 8.5 / 10  
- User B: 8.0 / 10  
- User C: 1.0 / 10  

---

## 💡 Key Findings

### ✅ What Worked

- Fast and responsive performance

- Intuitive task flow without onboarding

- Clear separation of task types

### 🚧 What Didn’t Work

- No priority system

- No reminders or scheduling

- No post-completion value or feedback

---

## 🚨 Core Insight

Users are not looking for another Todo app.

They are looking for a system that helps them improve.

The real gap was not functionality, but **feedback after execution**.

---

# 🚀 Transition to AURIX

This insight directly led to the design of AURIX.
AURIX is built to close the missing loop in productivity systems:
> Execution → Feedback → Improvement
Most Todo apps stop at execution.
AURIX introduces the missing layer: **learning from behavior.**

---

# 🧠 AI Productivity Coach

AURIX introduces a local AI system that analyzes personal productivity patterns.
Not a chatbot. Not a general assistant.
A system focused entirely on the user’s own data.

### Examples:
- Weekly productivity summaries

- Habit consistency tracking

- Task completion trends

- Goal progress analysis

- Personalized behavioral insights

---

### 💬 Example Insight

> Your long-term goals show lower completion rates over the past week.  
> Tasks started before 10 AM are significantly more likely to be completed.  
> Consider shifting high-priority work to the morning.

---

# 🔐 Local-first AI Architecture

Privacy is a core principle.
All data remains on-device.
No external APIs.

### Benefits:

- Offline-first operation
- Full local inference
- No cloud dependency
- Privacy by design
- Low operational cost

---

# 🤖 Why Gemma 2B?

Large models are powerful, but unnecessary for structured productivity data.
A lightweight local model works better because:
- Task data is small and structured
- Context is highly constrained
- Speed matters more than scale
- Privacy is critical

AURIX demonstrates a key idea:
> Smaller models become powerful when the system around them is designed correctly.

---

# 🛠 Tech Stack

### Logic
- C++

### AI
- Gemma 2B
- Ollama
- Local RAG


---

# 📈 Product Evolution

### V1: Todo Dashboard
- Basic task management
- Local-first architecture
- UX validation study
↓
### User Feedback
- No growth feedback loop
- No post-task value
- No behavioral insights
↓
### V2: AURIX
- AI Productivity Coach
- Local RAG system
- Behavioral analytics
- Weekly insights
- Habit tracking

---

# 🎯 Development Goals

- Build real products, not demos
- Validate through user behavior
- Keep privacy as default
- Iterate based on feedback, not assumptions
- Turn usage data into product evolution

---

# 🌱 Vision

AURIX is not another AI chatbot.
It is a **behavioral feedback system disguised as a productivity tool**.
A system that helps users understand how they work, and improve through evidence-based insights generated entirely on their own device.
