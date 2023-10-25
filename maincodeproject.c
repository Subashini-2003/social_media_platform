#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_POSTS 1000

typedef struct {
    char username[50];
    char password[50];
} User;

typedef struct {
    char message[200];
    char author[50];
} Post;

User users[MAX_USERS];
Post posts[MAX_POSTS];
int numUsers = 0;
int numPosts = 0;

void createUser(char username[], char password[]) {
    if (numUsers < MAX_USERS) {
        strcpy(users[numUsers].username, username);
        strcpy(users[numUsers].password, password);
        numUsers++;
        printf("User created successfully!\n");
    } else {
        printf("Maximum number of users reached.\n");
    }
}

int login(char username[], char password[]) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return i; // Return user index on successful login
        }
    }
    return -1; // Return -1 if login fails
}

void createPost(char message[], char author[]) {
    if (numPosts < MAX_POSTS) {
        strcpy(posts[numPosts].message, message);
        strcpy(posts[numPosts].author, author);
        numPosts++;
        printf("Post created successfully!\n");
    } else {
        printf("Maximum number of posts reached.\n");
    }
}

void displayNewsFeed(int userIndex) {
    printf("News Feed for %s:\n", users[userIndex].username);
    for (int i = numPosts - 1; i >= 0; i--) {
        printf("Author: %s\n", posts[i].author);
        printf("Message: %s\n\n", posts[i].message);
    }
}

int main() {
    int choice, userIndex;
    char username[50], password[50], message[200];

    while (1) {
        printf("\nSimple Social Media Platform (SSMP)\n");
        printf("1. Create User\n");
        printf("2. Login\n");
        printf("3. Create Post\n");
        printf("4. Display News Feed\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                createUser(username, password);
                break;

            case 2:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                userIndex = login(username, password);
                if (userIndex != -1) {
                    printf("Login successful!\n");
                } else {
                    printf("Login failed. Invalid username or password.\n");
                }
                break;

            case 3:
                if (userIndex != -1) {
                    printf("Enter your post: ");
                    getchar(); // Clear newline character from previous input
                    fgets(message, sizeof(message), stdin);
                    message[strlen(message) - 1] = '\0'; // Remove trailing newline
                    createPost(message, users[userIndex].username);
                } else {
                    printf("You need to log in first.\n");
                }
                break;

            case 4:
                if (userIndex != -1) {
                    displayNewsFeed(userIndex);
                } else {
                    printf("You need to log in first.\n");
                }
                break;

            case 5:
                printf("Exiting SSMP. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}