# student_data_base
This program makes a list of students with their percentage using single linked list and perform further operations on that list like saving into file, reading a file, deleting node etc.
if make command is not executing on your system then use following commands:
sudo apt update , 
sudo apt install make , 
make --version , 
# Student Database (Single Linked List)

This C program manages a list of students and their percentages using a singly linked list. You can add, delete, modify, sort, and save student records to a file.

## Features

- Add new student records
- Delete a student record by roll number
- Show all student records
- Modify a student record
- Sort the list by roll number
- Save all records to a file (`student_db.txt`)
- Delete all records

## Getting Started

### Prerequisites

- [GCC Compiler](https://gcc.gnu.org/)
- [Make](https://www.gnu.org/software/make/)
- Windows or Linux system

### Building the Project

1. **Clone or download this repository.**
2. **Open a terminal and navigate to the project folder.**

   On Windows:
   ```
   cd path\to\student_data_base-main\student_data_base-main
   ```

   On Linux:
   ```
   cd path/to/student_data_base-main/student_data_base-main
   ```

3. **Build the project using Make:**
   ```
   make -f SLL_makefile.txt
   ```

   If `make` is not installed, you can install it:

   - **On Ubuntu/Linux:**
     ```
     sudo apt update
     sudo apt install make
     ```

   - **On Windows:**  
     You can use [MinGW](http://www.mingw.org/) or [WSL](https://docs.microsoft.com/en-us/windows/wsl/) for GCC and Make.

   Or compile manually:
   ```
   gcc -c student_data_base.c
   gcc -c main_student_data_base.c
   gcc student_data_base.o main_student_data_base.o -o SLL.exe
   ```

### Running the Program

On Windows:
```
SLL.exe
```
On Linux:
```
./SLL
```

## Usage

Follow the on-screen menu to add, delete, modify, sort, or save student records.

## File Structure

- `main_student_data_base.c` — Main menu and program logic
- `student_data_base.c` — Linked list and student record functions
- `header.h` — Structure and function declarations
- `SLL_makefile.txt` — Makefile for building the project
- `student_db.txt` — File where student records are saved

## License

This project is for educational purposes.