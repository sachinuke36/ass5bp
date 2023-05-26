#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct stud_info
{
    char Name[50];
    char surname[50];
    int interest;
    int ID;
    int friends[100];
    int num_of_frnds;
};

struct stud_info stud[100];
int numStud = 0;

const char* getInterestName(int interest) {
    switch (interest) {
        case 0:
            return "Movie";
        case 1:
            return "Sports";
        case 2:
            return "Politics";
        case 3:
            return "Science";
        default:
            return "Unknown";
    }
}

void addPerson() {
    char firstName[20], surname[20];
    int interest;

    printf("Add new person in DB:\n");
    printf("Name: ");
    scanf("%s", firstName);
    printf("Surname: ");
    scanf("%s", surname);
    printf("Interest (0-Movie, 1-Sports, 2-Politics, 3-Science): ");
    scanf("%d", &interest);

    struct stud_info newStud;
    strcpy(newStud.Name, firstName);
    strcpy(newStud.surname, surname);
    newStud.interest = interest;
    newStud.ID = numStud;

    stud[numStud] = newStud;
    numStud++;
}

int main() {
    struct stud_info john = {"John", "Nash", 3, 0, {3, 6}, 2};
    struct stud_info george = {"George", "Bush", 2, 1, {2, 3, 7}, 3};
    struct stud_info barack = {"Barack", "Obama", 2, 2, {1}, 1};
    struct stud_info isaac = {"Isaac", "Newton", 3, 3, {0, 1}, 2};
    struct stud_info allan = {"Allan", "Border", 1, 4, {5}, 1};
    struct stud_info sunil = {"Sunil", "Gavaskar", 1, 5, {4}, 1};
    struct stud_info marlon = {"Marlon", "Brando", 0, 6, {0, 7}, 2};
    struct stud_info leo = {"Leo", "Caprio", 0, 7, {1, 6, 8}, 3};

    stud[0] = john;
    stud[1] = george;
    stud[2] = barack;
    stud[3] = isaac;
    stud[4] = allan;
    stud[5] = sunil;
    stud[6] = marlon;
    stud[7] = leo;

    numStud = 8;

    int input = 1;

    while(1)
       { printf("Enter 0 to exit or 1 to add a new person: ");
        scanf("%d", &input);

        if (input == 1) {
            addPerson();
        }
        else break;
       }
    

    // Print the student information
    for (int i = 0; i < numStud; i++) {
        printf("Student ID: %d\n", stud[i].ID);
        printf("Name: %s %s\n", stud[i].Name, stud[i].surname);
        printf("Interest: %s\n", getInterestName(stud[i].interest));
        printf("Number of Friends: %d\n", stud[i].num_of_frnds);
        printf("Friends: ");
        for (int j = 0; j < stud[i].num_of_frnds; j++) {
            printf("%d ", stud[i].friends[j]);
        }
        printf("\n\n");
    }

    return 0;
}
