#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Activity {
    char date[20];
    char taskName[50];
    char description[200];
};

void addActivity() {
    struct Activity a;
    FILE *fp = fopen("diary.txt", "a");

    printf("\nEnter Date (DD/MM/YYYY): ");
    scanf("%s", a.date);

    printf("Enter Task Name: ");
    scanf(" %[^\n]", a.taskName);

    printf("Enter Task Description: ");
    scanf(" %[^\n]", a.description);

    fprintf(fp, "%s|%s|%s\n", a.date, a.taskName, a.description);
    fclose(fp);

    printf("\nActivity added successfully!\n");
}

void viewActivities() {
    FILE *fp = fopen("diary.txt", "r");
    struct Activity a;

    if (!fp) {
        printf("\nNo entries found!\n");
        return;
    }

    printf("\n------- Department Diary -------\n");

    while (fscanf(fp, "%[^|]|%[^|]|%[^\n]\n", a.date, a.taskName, a.description) != EOF) {
        printf("\nDate: %s\nTask: %s\nDescription: %s\n", a.date, a.taskName, a.description);
    }
    fclose(fp);
}

void searchActivity() {
    FILE *fp = fopen("diary.txt", "r");
    struct Activity a;
    char searchDate[20];
    int found = 0;

    printf("\nEnter date to search (DD/MM/YYYY): ");
    scanf("%s", searchDate);

    while (fscanf(fp, "%[^|]|%[^|]|%[^\n]\n", a.date, a.taskName, a.description) != EOF) {
        if (strcmp(a.date, searchDate) == 0) {
            printf("\nDate: %s\nTask: %s\nDescription: %s\n",
                   a.date, a.taskName, a.description);
            found = 1;
        }
    }
    fclose(fp);

    if (!found)
        printf("\nNo records found on this date.\n");
}

void deleteActivity() {
    FILE *fp = fopen("diary.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    struct Activity a;
    char delDate[20];
    int found = 0;

    printf("\nEnter the date of the activity to delete: ");
    scanf("%s", delDate);

    while (fscanf(fp, "%[^|]|%[^|]|%[^\n]\n", a.date, a.taskName, a.description) != EOF) {
        if (strcmp(a.date, delDate) != 0) {
            fprintf(temp, "%s|%s|%s\n", a.date, a.taskName, a.description);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("diary.txt");
    rename("temp.txt", "diary.txt");

    if (found)
        printf("\nActivity deleted successfully!\n");
    else
        printf("\nNo activity found on that date.\n");
}

void editActivity() {
    FILE *fp = fopen("diary.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    struct Activity a;
    char editDate[20];
    int found = 0;

    printf("\nEnter the date of the activity to edit: ");
    scanf("%s", editDate);

    while (fscanf(fp, "%[^|]|%[^|]|%[^\n]\n", a.date, a.taskName, a.description) != EOF) {
        if (strcmp(a.date, editDate) == 0) {
            found = 1;
            printf("\nEnter new Task Name: ");
            scanf(" %[^\n]", a.taskName);

            printf("Enter new Description: ");
            scanf(" %[^\n]", a.description);
        }
        fprintf(temp, "%s|%s|%s\n", a.date, a.taskName, a.description);
    }

    fclose(fp);
    fclose(temp);

    remove("diary.txt");
    rename("temp.txt", "diary.txt");

    if (found)
        printf("\nActivity updated successfully!\n");
    else
        printf("\nNo activity found on that date.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n===============================");
        printf("\n Department Activity Diary");
        printf("\n===============================\n");
        printf("1. Add Activity\n");
        printf("2. View All Activities\n");
        printf("3. Search Activity\n");
        printf("4. Edit Activity\n");
        printf("5. Delete Activity\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addActivity(); break;
            case 2: viewActivities(); break;
            case 3: searchActivity(); break;
            case 4: editActivity(); break;
            case 5: deleteActivity(); break;
            case 6: exit(0);
            default: printf("\nInvalid choice!\n");
        }
    }

    return 0;
}
