#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_TASK_LENGTH 256
#define FILE_NAME "todo_list.txt"

typedef struct {
    char description[MAX_TASK_LENGTH];
    int completed;
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;

void load_tasks() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        return;
    }

    while (task_count < MAX_TASKS && fscanf(file, "%d|%[^\n]\n", &tasks[task_count].completed, tasks[task_count].description) == 2) {
        task_count++;
    }
    fclose(file);
}

void save_tasks() {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Error saving tasks!\n");
        return;
    }

    for (int i = 0; i < task_count; i++) {
        fprintf(file, "%d|%s\n", tasks[i].completed, tasks[i].description);
    }
    fclose(file);
}

void add_task(char *description) {
    if (task_count >= MAX_TASKS) {
        printf("Task list is full!\n");
        return;
    }

    strncpy(tasks[task_count].description, description, MAX_TASK_LENGTH - 1);
    tasks[task_count].description[MAX_TASK_LENGTH - 1] = '\0';
    tasks[task_count].completed = 0;
    task_count++;
    save_tasks();
    printf("Task added: %s\n", description);
}

void list_tasks() {
    if (task_count == 0) {
        printf("No tasks available.\n");
        return;
    }

    printf("\nTo-Do List:\n");
    for (int i = 0; i < task_count; i++) {
        printf("%d. %s [%s]\n", i + 1, tasks[i].description, tasks[i].completed ? "Completed" : "Pending");
    }
}

void complete_task(int index) {
    if (index < 1 || index > task_count) {
        printf("Invalid task number!\n");
        return;
    }

    tasks[index - 1].completed = 1;
    save_tasks();
    printf("Task %d marked as completed.\n", index);
}

void delete_task(int index) {
    if (index < 1 || index > task_count) {
        printf("Invalid task number!\n");
        return;
    }

    for (int i = index - 1; i < task_count - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    task_count--;
    save_tasks();
    printf("Task %d deleted.\n", index);
}

void print_usage() {
    printf("\nUsage:\n");
    printf("  a <task>  - Add a new task\n");
    printf("  l        - List all tasks\n");
    printf("  c <num>  - Complete task number <num>\n");
    printf("  d <num>  - Delete task number <num>\n");
    printf("  q        - Quit\n\n");
}

int main() {
    load_tasks();
    char command;
    char description[MAX_TASK_LENGTH];
    int task_num;

    printf("To-Do List Manager\n");
    print_usage();

    while (1) {
        printf("Enter command: ");
        scanf(" %c", &command);

        switch (command) {
            case 'a':
                scanf(" %[^\n]", description);
                add_task(description);
                break;
            case 'l':
                list_tasks();
                break;
            case 'c':
                scanf("%d", &task_num);
                complete_task(task_num);
                break;
            case 'd':
                scanf("%d", &task_num);
                delete_task(task_num);
                break;
            case 'q':
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid command!\n");
                print_usage();
        }
    }

    return 0;
}
