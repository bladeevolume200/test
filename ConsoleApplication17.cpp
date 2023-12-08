#include <iostream>

using namespace std;

struct Task {
    char title[50];
    int priority;
    char description[200];
    char datetime[50];
};

const int MAX_TASKS = 100;
Task tasks[MAX_TASKS];
int numTasks = 0;

void addTask() {
    if (numTasks >= MAX_TASKS) {
        cout << "Task list is full\n";
        return;
    }
    Task& newTask = tasks[numTasks++];
    cout << "Enter title: ";
    cin.getline(newTask.title, 50);
    cout << "Enter priority: ";
    cin >> newTask.priority;
    cin.ignore();
    cout << "Enter description: ";
    cin.getline(newTask.description, 200);
    cout << "Enter date and time: ";
    cin.getline(newTask.datetime, 50);
}

void deleteTask() {
    char title[50];
    cout << "Enter the title of the task to delete: ";
    cin.getline(title, 50);
    for (int i = 0; i < numTasks; i++) {
        if (strcmp(tasks[i].title, title) == 0) {
            tasks[i] = tasks[--numTasks];
            break;
        }
    }
}

void displayTasks() {
    for (int i = 0; i < numTasks; i++) {
        const Task& task = tasks[i];
        cout << "Title: " << task.title << "\n";
        cout << "Priority: " << task.priority << "\n";
        cout << "Description: " << task.description << "\n";
        cout << "Date and Time: " << task.datetime << "\n\n";
    }
}

int main() {
    while (true) {
        cout << "1. Add task\n";
        cout << "2. Delete task\n";
        cout << "3. Display tasks\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1:
            addTask();
            break;
        case 2:
            deleteTask();
            break;
        case 3:
            displayTasks();
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice\n";
        }
    }
}
