#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 100

struct Candidate {
    int id;
    char name[50];
    char email[50];
    char phone[20];
    char qualification[50];
};

struct Candidate candidates[MAX_CANDIDATES];
int numCandidates = 0;

int updateCandidateDetails() {
    int candidateID, found = 0;
    printf("Enter candidate ID to update details: ");
    scanf("%d", &candidateID);
    for (int i = 0; i < numCandidates; i++) {
        if (candidates[i].id == candidateID) {
            found = 1;
            printf("Enter updated details for candidate %d:\n", candidateID);
            printf("Name: ");
            scanf("%s", candidates[i].name);
            printf("Email: ");
            scanf("%s", candidates[i].email);
            printf("Phone: ");
            scanf("%s", candidates[i].phone);
            printf("Qualification: ");
            scanf("%s", candidates[i].qualification);
            printf("Candidate details updated successfully.\n");

            // Save the updated details to a file
            FILE *fp;
            fp = fopen("candidates.txt", "w");
            if (fp == NULL) {
                printf("Error opening file.\n");
                return 0;
            }
            for (int j = 0; j < numCandidates; j++) {
                fprintf(fp, "%d %s %s %s %s\n", candidates[j].id, candidates[j].name, candidates[j].email, candidates[j].phone, candidates[j].qualification);
            }
            fclose(fp);

            break;
        }
    }
    if (!found) {
        printf("Candidate with ID %d not found.\n", candidateID);
    }
    return 1;
}

int main() {
    // Read the candidate details from a file
    FILE *fp;
    fp = fopen("candidates.txt", "r");
    if (fp != NULL) {
        while (fscanf(fp, "%d %s %s %s %s", &candidates[numCandidates].id, candidates[numCandidates].name, candidates[numCandidates].email, candidates[numCandidates].phone, candidates[numCandidates].qualification) != EOF) {
            numCandidates++;
        }
        fclose(fp);
    }

    // Initialize candidates with some sample data if file is empty
    if (numCandidates == 0) {
        candidates[0].id = 1001;
        strcpy(candidates[0].name, "Manjodh");
        strcpy(candidates[0].email, "manjodh.bh@email.com");
        strcpy(candidates[0].phone, "123-456-7890");
        strcpy(candidates[0].qualification, "B.E. Computer Science");

        candidates[1].id = 1002;
        strcpy(candidates[1].name, "Tanveer");
        strcpy(candidates[1].email, "tanveer.hu@email.com");
        strcpy(candidates[1].phone, "987-654-3210");
        strcpy(candidates[1].qualification, "B.Tech. Information Technology");

        numCandidates = 2;
    }

    updateCandidateDetails();

    return 0;
}