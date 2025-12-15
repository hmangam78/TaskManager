# TaskManager

A C++20-based command-line task management application designed to help organize, track, and manage tasks efficiently.

## Overview

TaskManager is a lightweight task management system that allows users to:
- Create and manage tasks with custom tags
- Track task creation and completion dates
- Save and load tasks from CSV files
- View tasks in a formatted list
- Mark tasks as completed
- Delete tasks from the list

## Features

- **Task Management**: Add, view, delete, and complete tasks
- **Date Tracking**: Automatic recording of task creation and completion dates using C++20 chrono library
- **File Persistence**: Save and load tasks from CSV format for data persistence
- **Custom Tags**: Organize tasks with customizable tags (e.g., URGENT, WORK, PERSONAL)
- **Clean CLI**: Command-line interface for intuitive interaction

## Requirements

- **C++20 or later**
- **GCC/Clang compiler** supporting C++20
- **GNU Make**

## Building the Project

### Using Make

```bash
cd /home/hector/MyProjects/TaskManager
make
```

This will compile the project and generate the `task_manager` executable.

### Cleaning Build Files

```bash
make clean
```

## Project Structure

```
TaskManager/
├── includes/
│   ├── Task.hpp           # Task class declaration
│   └── TaskList.hpp       # TaskList class declaration
├── SRCS/
│   ├── main.cpp           # Application entry point
│   ├── Task.cpp           # Task class implementation
│   ├── TaskList.cpp       # TaskList class implementation
│   └── taskmanager.hpp    # Main header file
├── Makefile               # Build configuration
└── README.md              # This file
```

## Usage

### Running the Application

```bash
./task_manager [command] [options]
```

### Available Commands (In Development)

- `add <task_name> <tag>` - Add a new task
- `view` - Display all tasks
- `complete <task_id>` - Mark a task as completed
- `delete <task_id>` - Remove a task

### Example

```bash
# Add a task
./task_manager add "Buy groceries" PERSONAL

# View all tasks
./task_manager view

# Complete a task
./task_manager complete 0

# Delete a task
./task_manager delete 0
```

## Data Format

Tasks are stored in `tasks.csv` with the following format:

```
task_name|tag|status|creation_timestamp|completion_timestamp
Buy groceries|PERSONAL|0|1671038400|0
Finish project|WORK|1|1670000000|1671038400
```

**Fields**:
- `task_name`: Description of the task
- `tag`: Category tag for organization
- `status`: 0 (incomplete) or 1 (completed)
- `creation_timestamp`: Unix timestamp of task creation
- `completion_timestamp`: Unix timestamp of completion (0 if not completed)

## Implementation Details

### Key Classes

#### Task
Represents a single task with the following attributes:
- Task description
- Tag/category
- Completion status
- Creation date (`std::chrono::system_clock::time_point`)
- Completion date (`std::optional<std::chrono::system_clock::time_point>`)

#### TaskList
Manages a collection of tasks with methods for:
- Adding tasks
- Removing tasks
- Loading from file
- Saving to file
- Displaying tasks

### Technology Stack

- **C++20**: Modern C++ features including `std::optional` for nullable types
- **chrono**: For date and time management
- **fstream**: File I/O operations
- **vector**: Dynamic task storage

## Development Status

🚧 **In Development**

Currently implemented:
- ✅ Task class with date tracking
- ✅ TaskList collection management
- ✅ CSV file persistence (load/save)
- ✅ Task display with formatting

In Progress:
- 🔄 Command-line argument parsing
- 🔄 Complete CLI interface
- 🔄 Archive functionality
- 🔄 Task filtering and search

## Compilation Flags

The project compiles with these flags:
- `-std=c++20` - Enable C++20 standard
- `-Wall -Wextra` - Enable all warnings

## Future Enhancements

- Task archiving system
- Task search and filtering
- Due date functionality
- Task priority levels
- Data export to JSON format
- Database backend support
- Web API interface

## License

This project is created for educational purposes.

## Author

Hector Gamiz - 42 Malaga
