# Trie-Based-Auto-Suggestion-
Auto-suggestion website using C++ (CGI) and Trie for real-time prefix matching.
# Trie-Based Auto Suggestion System (C++ + CGI)

🚀 A fast and efficient **auto-suggestion system** built using **C++ and Trie data structure**, integrated with a **browser-based HTML interface** using **CGI (Common Gateway Interface)**.

This project is designed to demonstrate how data structures like Trie can power real-time word prediction systems similar to those found in search engines and mobile keyboards.

---

## 📌 Features

- 🔍 Real-time word suggestions based on user prefix input
- ⚡ Fast search using Trie (prefix tree)
- 🧠 Case-insensitive matching
- 🌐 Web-based UI using HTML and JavaScript
- 📂 Suggests from a dictionary stored in `words.txt`
- 📦 Built with **C++**, served via **Apache CGI**

---

## 🧱 Technologies Used

- C++ (core logic + file handling)
- Trie Data Structure
- CGI (Common Gateway Interface)
- HTML + JavaScript (Frontend)
- XAMPP / Apache Web Server

---

## 📂 Project Structure

├── index.html # User interface (web page)
├── new.cpp # Main C++ backend logic
├── suggest.exe # Compiled executable (CGI)
├── words.txt # Word dictionary (one word per line)


---

## 🚀 How to Run

### ✅ Prerequisites

- [XAMPP](https://www.apachefriends.org/index.html) installed and Apache running
- `g++` compiler (MinGW for Windows or GCC for Linux)
- A modern web browser (Chrome, Firefox, etc.)

---

### 🔧 Setup Steps

1. **Clone this repository or download the files**
2. **Place files:**

   - `index.html`, `new.cpp` → `C:\xampp\htdocs\your-folder`
   - `suggest.exe`, `words.txt` → `C:\xampp\cgi-bin`

3. **Compile the C++ code:**

   ```bash
   g++ new.cpp -o suggest.exe
   copy suggest.exe C:\xampp\cgi-bin\ /Y

Start Apache server from XAMPP Control Panel

Access your app:
http://localhost/your-folder/index.html

Start typing — suggestions will appear as you type!


<img width="2879" height="1632" alt="image" src="https://github.com/user-attachments/assets/207fd50d-9485-44e8-acee-a5c0f6732415" />

Example Words (words.txt)
apple
apply
application
artificial
banana
basket
build
business
buzz
...
We can add up to 5000 words (1 per line) to avoid performance issues.

💡 Use Cases
🔠 Keyboard suggestion engines

🔍 Search bar autocomplete

🧠 Smart form fillers

🎓 DSA project portfolio
