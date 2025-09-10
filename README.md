# To-Do List Manager

A simple command-line To-Do List Manager written in C that allows users to manage daily tasks. Users can add tasks, list all tasks, mark tasks as completed, and delete tasks. The task list persists between program runs by saving to and loading from a text file (`todo_list.txt`).

## Features
- **Add Tasks**: Add new tasks with a description.
- **List Tasks**: Display all tasks with their status (Pending or Completed).
- **Complete Tasks**: Mark a specific task as completed.
- **Delete Tasks**: Remove a specific task from the list.
- **Persistent Storage**: Tasks are saved to `todo_list.txt` and loaded on program start.

## Requirements
- C compiler (e.g., `gcc`)
- Standard C libraries

## Installation
1. Clone or download the project files.
2. Ensure you have a C compiler installed (e.g., `gcc`).
3. Compile the program:
   ```bash
   gcc todo.c -o todo
   ```

## Usage
Run the program:
```bash
./todo
```

### Commands
- `a <task>`: Add a new task (e.g., `a Buy groceries`).
- `l`: List all tasks.
- `c <num>`: Mark task number `<num>` as completed (e.g., `c 1`).
- `d <num>`: Delete task number `<num>` (e.g., `d 1`).
- `q`: Quit the program.

### Example
```
To-Do List Manager
Usage:
  a <task>  - Add a new task
  l        - List all tasks
  c <num>  - Complete task number <num>
  d <num>  - Delete task number <num>
  q        - Quit

Enter command: a Buy groceries
Task added: Buy groceries
Enter command: l
To-Do List:
1. Buy groceries [Pending]
Enter command: c 1
Task 1 marked as completed.
Enter command: l
To-Do List:
1. Buy groceries [Completed]
Enter command: q
Goodbye!
```

## File Storage
- Tasks are stored in `todo_list.txt` in the same directory as the executable.
- Each line in the file represents a task in the format: `<completed>|<description>`, where `<completed>` is `0` (Pending) or `1` (Completed).

## Limitations
- Maximum of 100 tasks.
- Task descriptions are limited to 255 characters.
- No support for editing task descriptions.

## License
This project is open-source and available under the MIT License.
