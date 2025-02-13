# Learn and Teach Programming Languages

![C++](https://img.shields.io/badge/C++-Programming-blue)
![File Handling](https://img.shields.io/badge/File-Handling-green)
![Education](https://img.shields.io/badge/Education-Platform-orange)

A C++ project for a platform that facilitates programming language learning and teaching. Students can register, log in, and enroll in courses, while teachers can register, log in,  add courses, and delete courses. This project was developed as part of my 2nd semester coursework to enhance my understanding of C++ programming concepts, including OOP concepts( Encapsulation, Inheritance, Polymorphism and Abstraction), file handling, user input management, and function-based programming.

---

## Table of Contents

1. [Features](#-features)
2. [Installation](#-installation)
3. [Usage](#-usage)
4. [File Structure](#%EF%B8%8F-file-structure)
5. [Contributing](#-contributing)
6. [Documentation](#-generate-and-view-documentation)

---

## 📌 Features

- **Student Features**:
  - Register with name, registration number, and session.
  - Log in to the platform.
  - View available courses.
  - Enroll in a course.

- **Teacher Features**:
  - Register with name, email, and registration number.
  - Log in to the platform.
  - Add a new course with language name, topics, learning hours, and tools.
  - Delete a course.

- **General Features**:
  - View all available courses.
  - File-based data storage for students, teachers, courses, and enrollments.
    
- **OOP Features**:
  - **Encapsulation:** Student, Teacher, and Course classes encapsulate data and behavior.
  - **Inheritance:** Student and Teacher inherit from User.
  - **Polymorphism:** displayMenu() is a virtual function overridden by child classes.
  - **Abstraction:** Users interact with an easy-to-use interface.

---

## 🚀 Installation

### Prerequisites

- **C++ Compiler**: Ensure you have a C++ compiler installed (e.g., `g++`).
- **Git**: To clone the repository.

### Steps

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/Learn-and-Teach-Programming-Languages.git
   ```
2. Navigate to the project directory:
   ```bash
   cd Learn-and-Teach-Programming-Languages
   ```
3. Compile the program:
   ```bash
   g++ -o learn_teach learn_teach.cpp
   ```

---

## 📝 Usage

1. Run the program:
   ```bash
   ./learn_teach
   ```
2. Follow the on-screen instructions:
   - Choose to **Learn Programming**, **Teach Programming**, or **View Courses**.
   - Register or log in as a student or teacher.
   - Enroll in courses (students) or add/delete courses (teachers).

---

## 🛠️ File Structure

```
learn-teach-programming/
├── learn_teach.cpp       # Main C++ source code
├── students.txt          # Stores student registration data
├── teachers.txt          # Stores teacher registration data
├── courses.txt           # Stores course details
├── enrollments.txt       # Stores course enrollment data
├── README.md             # Project documentation
```

---

## 🤝 Contributing

Contributions are welcome! Follow these steps:

1. Fork the repository.
2. Create a new branch:
   ```bash
   git checkout -b feature/your-feature-name
   ```
3. Commit your changes:
   ```bash
   git commit -m "Add your feature"
   ```
4. Push to the branch:
   ```bash
   git push origin feature/your-feature-name
   ```
5. Open a pull request.

---

## 📜 Generate and View Documentation
This project uses Doxygen for documentation.

#### 1️⃣ Install Doxygen
##### Windows: 
Download from [Doxygen Official Site](http://www.doxygen.nl/).

##### Linux/macOS:
Install via terminal:
```sh
sudo apt install doxygen    # Ubuntu/Debian
sudo yum install doxygen    # Fedora
brew install doxygen        # macOS
```

#### 2️⃣ Generate Documentation
Run this command in the project directory:

```sh
doxygen Doxyfile
```

This will create a `docs/html/` folder containing the documentation.

#### 3️⃣ View Documentation
Open `docs/html/index.html` in a web browser to view the documentation.
---


