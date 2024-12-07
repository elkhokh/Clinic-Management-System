
/*=================================================================================*/
/*  @File        : main.c                                                          */
/*  @Description : the clinic system by c programming                            */
/*  @Author      : Mustafa khaled Elkhokh                                          */
/*  @Date        : 10/9/2024                                                       */
/*  @mail        : mustafaelkhokhy@gmil.com                                        */
/*=================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "STD_TYPES.h"

#define MaxSizeName 40
#define MaxSizeGender 10
#define MAX 5

typedef struct listpatient
{
    int id, age, slot;
    char name[MaxSizeName];
    char gender[MaxSizeGender];
    struct listpatient *Next;
} ListPatient;
typedef struct linkedlist
{
    ListPatient *Head;
    int size;
} List_Patients;
/* Functions Decleration to List_Patient */

void List_voidInitList(List_Patients *PL);
void List_voidInsertList(List_Patients *PL, int *id, int *age, char *name, char *gender, int *slot);
void List_voidInsertLast(List_Patients *PL, int *id, int *age, char *name, char *gender);
void List_voidReplaceList(List_Patients *PL, int *id, int *age, char *name, char *gender, int *slot);
void List_voidPrintList(List_Patients *PL, int id);
int List_intisEmpty(List_Patients *PL);
int List_intSizeList(List_Patients *PL);
int List_voidCheckIDList(List_Patients *PL, int id);

void PrintFreeSlots(void);
void PrintReservationSlots(void);
int CheckUniqeID_Slot(int *id);

int Slot[MAX] = {0, 0, 0, 0, 0};
int flag = 0;
int id, age, pos, slot, exit_program = 0;

int main()
{
    List_Patients L1;
    List_Patients *PL1 = &L1;
    int mode, size;
    List_voidInitList(PL1);
    char name[MaxSizeName];
    char gender[MaxSizeGender];
    int feature = 1;
    while (exit_program == 0)
    {
         printf("\n");
        printf("        ----------------------------------------------- \n");
        printf("        ----------------------------------------------- \n");
        printf("           <<< \"(^_^)  W  E  L  C  O M  E  (^_^) \" >>>\n");
        printf("        ----------------------------------------------- \n");
        printf("        ----------------------------------------------- \n\n");
        printf("------------------------------------\n");
        printf(" Enter Position Between Modes: \n");
        printf("------------------------------------\n");
        printf("  Admain Mode Input >>>> [1]\n");
        printf("  User Mode Input   >>>> [2]\n");
        printf("  To End Input      >>>> [0]\n");
        printf("------------------------------------\n");
        printf(" The Position :");
        scanf("%d", &mode);
        printf(" --------------------------\n");
        switch (mode)
        {
        case 0:
            system("cls");
        printf("          -------------------------------------------\n");
        printf("          -------------------------------------------\n");
        printf("                <<<<<(^_^)  GoodBye  (^_^)>>>>>\n");
        printf("          -------------------------------------------\n");
        printf("          -------------------------------------------\n");
            exit_program++;
            break;
        case 1:
            system("cls");
            printf(" Please Enter Admin Password : ");
            for (int i = 0; i < 3; i++)
            {
                int pass;
                scanf("%d", &pass);

                if (pass == 1234)
                {
                    system("cls");
        printf("-------------------------------------------\n");
        printf("-------------------------------------------\n");
        printf("   <<<<<(^_^)  Welcome Admin  (^_^)>>>>>\n");
        printf("-------------------------------------------\n");
        printf("-------------------------------------------\n");
                    while (feature != 0)
                    {
                        printf(" ------------------------------------\n");
                        printf(" Add New Patient Record ------------> [1]\n");
                        printf(" Edit Patient Record ---------------> [2]\n");
                        printf(" Reserve a Slot with the Doctor ----> [3]\n");
                        printf(" Cancel Reservation ----------------> [4]\n");
                        printf(" Back to Main Window ---------------> [0]\n");
                        printf(" ------------------------------------\n");
                        printf(" Select Number of Feature : ");
                        scanf("%d", &feature);
                        system("cls");
                        switch (feature)
                        {
                        case 0:
                            feature = 0;
                            break;
                        case 1:
                            // Add New Patient.
                            printf(" Enter Patient ID : ");
                            scanf("%d", &id);
                            // Check id is uniqe or not
                            if (List_voidCheckIDList(PL1, id) == 0)
                            {
                                printf(" Enter Patient age : ");
                                scanf("%d", &age);
                                printf(" Enter Patient Name : ");
                                scanf("%s", name);
                                printf(" Enter Patient Gender : ");
                                scanf("%s", gender);
                                if (List_intisEmpty(PL1))
                                {
                                    pos = 0;
                                    List_voidInsertList(PL1, &id, &age, name, gender, &pos);
                                }
                                else
                                {
                                    List_voidInsertLast(PL1, &id, &age, name, gender);
                                }
                                printf(" *******************************\n");
                                printf("    Insertion Successful (^-^) \n");
                                printf(" *******************************\n");
                            }
                            else
                            {
                                system("cls");
                                printf(" Sorry You Can't Use This ID !!\n");
                            }
                            break;
                        case 2: // Edit Patient Record
                            if (!List_intisEmpty(PL1))
                            {
                                printf(" Enter Patient ID : ");
                                scanf("%d", &id);
                                pos = List_voidCheckIDList(PL1, id);
                                if (pos != 0)
                                {
                                    printf(" Enter Patient New age : ");
                                    scanf("%d", &age);
                                    printf(" Enter Patient New Name : ");
                                    scanf("%s", name);
                                    printf(" Enter Patient New Gender : ");
                                    scanf("%s", gender);
                                    pos--;
                                    List_voidReplaceList(PL1, &id, &age, name, gender, &pos);
                                    system("cls");
                                    printf(" *******************************\n");
                                    printf("    Edit is Successful (^-^) \n");
                                    printf(" *******************************\n");
                                }
                                else
                                {
                                    system("cls");
                                    printf(" **********************\n");
                                    printf(" Sorry, Incorrect ID !!\n");
                                    printf(" **********************\n");
                                }
                            }
                            else
                            {
                                system("cls");
                                printf(" ***************************************\n");
                                printf(" Sorry, The List of Patients is Empty !!\n");
                                printf(" ***************************************\n");
                            }
                            break;
                        case 3: // Reserve a slot
                            PrintFreeSlots();
                            if (flag != 5)
                            {
                                printf(" Enter the ID : ");
                                scanf("%d", &id);
                                if (CheckUniqeID_Slot(&id) == 1)
                                {
                                    printf(" Select Needed Slot : ");
                                    scanf("%d", &slot);
                                    Slot[slot] = id;
                                    system("cls");
                                    printf(" *******************************\n");
                                    printf("   Rservation Successful (^-^) \n");
                                    printf(" *******************************\n");
                                }
                                else
                                {
                                    system("cls");
                                    printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
                                    printf(" Sorry You Can't Use This ID !!\n");
                                    printf(" This ID is Reserved already !!\n");
                                    printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
                                }
                            }
                            break;
                        case 4: // Cancel Reservation
                            printf(" Enter the ID : ");
                            scanf("%d", &id);
                            for (int i = 0; i < MAX; i++)
                            {
                                if (Slot[i] == id)
                                {
                                    Slot[i] = 0;
                                    system("cls");
                                    printf(" ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
                                    printf("     reservation of This ID Was Deleted \n");
                                    printf(" ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
                                }
                            }
                            break;
                        default:
                            break;
                        }
                    }
                    break;
                }
                else
                {
                    if (i == 2)
                    {
                        system("cls");
                        printf(" **********************************************\n");
                        printf(" Incorrect Password for 3 times, No more tries \n");
                        printf(" **********************************************\n");
                        exit_program++;
                        break;
                    }
                    else
                    {
                        printf("xxxxxxxxxxxxx\n");
                        printf(" Try again : ");
                    }
                }
            }
            break;
        case 2:
            system("cls");
            printf("*******************************\n");
            printf(" <<<<<<<< Welcome User >>>>>>> \n");
            printf("*******************************\n");
            while (feature != 3)
            {
                printf(" ---------------------------------\n");
                printf(" View Patient Record ------------> [1]\n");
                printf(" View Todays Reservations -------> [2]\n");
                printf(" Back to Main Window ------------> [3]\n");
                printf(" ---------------------------------\n");
                printf(" Select Number of Feature : ");
                scanf("%d", &feature);
                system("cls");
                switch (feature)
                {
                case 1: // View Patient Record.
                    if (!List_intisEmpty(PL1))
                    {
                        printf(" Enter Patient ID : ");
                        scanf("%d", &id);
                        if (List_voidCheckIDList(PL1, id) == 0)
                        {
                            system("cls");
                            printf(" **********************\n");
                            printf(" Sorry, Incorrect ID !!\n");
                            printf(" **********************\n");
                        }
                        else
                        {
                            List_voidPrintList(PL1, id);
                            for (int i = 0; i < MAX; i++)
                            {
                                if (Slot[i] == id)
                                {
                                    switch (i)
                                    {
                                    case 0:
                                        printf(" ID %d Reserve Slot %d From 2pm To 2:30pm \n", Slot[i], i);
                                        break;
                                    case 1:
                                        printf(" ID %d Reserve Slot %d From 2:30pm To 3pm \n", Slot[i], i);
                                        break;
                                    case 2:
                                        printf(" ID %d Reserve Slot %d From 3pm To 3:30pm \n", Slot[i], i);
                                        break;
                                    case 3:
                                        printf(" ID %d Reserve Slot %d From 3:30pm To 4pm \n", Slot[i], i);
                                        break;
                                    case 4:
                                        printf(" ID %d Reserve Slot %d From 4:30pm To 5pm \n", Slot[i], i);
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        system("cls");
                        printf(" ***************************************\n");
                        printf(" Sorry, The List of Patients is Empty !!\n");
                        printf(" ***************************************\n");
                    }
                    break;
                case 2: // View Todays Reservation.
                    PrintReservationSlots();
                    break;
                default:
                    break;
                }
            }
            break;
        }
    }
    return 0;
}
// Check id is Uniqe or not ?
int CheckUniqeID_Slot(int *id)
{
    int counter = 0;
    for (int i = 0; i < MAX; i++)
    {
        if (Slot[i] == *id)
            counter++;
    }
    if (counter == 0)
        return 1;
    else
        return 0;
}
void List_voidInitList(List_Patients *PL)
{
    PL->Head = NULL;
    PL->size = 0;
}
void List_voidInsertList(List_Patients *PL, int *id, int *age, char *name, char *gender, int *slot)
{
    // Create New ListPatient by dynamic memory allocation and Assign ListPatient Pointer at (pn).
    ListPatient *pn = (ListPatient *)malloc(sizeof(ListPatient));
    // Assign The Copy of Value at Data of the New Node.
    pn->id = *id;
    pn->age = *age;
    for (int i = 0; i < MaxSizeName; i++)
    {
        pn->name[i] = name[i];
    }
    for (int i = 0; i < MaxSizeGender; i++)
    {
        pn->gender[i] = gender[i];
    }

    // case 1 at insert first node on position 0.
    if (*slot == 0)
    {
        pn->Next = PL->Head;
        PL->Head = pn;
    }
    // case 2 at insert any node on any position.
    else
    {
        // Create New Temporary Pointer.
        ListPatient *Temp = PL->Head;
        // Traverse loop to put Temp pointer at the node that have position-1 .
        for (int i = 0; i < ((*slot) - 1); i++)
        {
            Temp = Temp->Next;
        }
        pn->Next = Temp->Next;
        Temp->Next = pn;
    }
    // Increment Size of List Nodes.
    PL->size++;
}
void List_voidInsertLast(List_Patients *PL, int *id, int *age, char *name, char *gender)
{
    // Create New ListPatient by dynamic memory allocation and Assign ListPatient Pointer at (pn).
    ListPatient *pn = (ListPatient *)malloc(sizeof(ListPatient));
    // Assign The Copy of Value at Data of the New Node.
    pn->id = *id;
    pn->age = *age;
    for (int i = 0; i < MaxSizeName; i++)
    {
        pn->name[i] = name[i];
    }
    for (int i = 0; i < MaxSizeGender; i++)
    {
        pn->gender[i] = gender[i];
    }
    // Create New Temporary Pointer.
    ListPatient *Temp = PL->Head;
    // Traverse loop to put Temp pointer at the node that have Last position.
    for (int i = 0; i < PL->size - 1; i++)
    {
        Temp = Temp->Next;
    }
    pn->Next = Temp->Next;
    Temp->Next = pn;
    // Increment Size of List Nodes.
    PL->size++;
}
void List_voidReplaceList(List_Patients *PL, int *id, int *age, char *name, char *gender, int *slot)
{
    // Create New Temporary Pointer.
    ListPatient *Temp = PL->Head;
    // Traverse loop to put Temp pointer at the node that have the position we need replace her data.
    for (int i = 0; i < *slot; i++)
    {
        Temp = Temp->Next;
    }
    // Assign the new data at the node.
    Temp->id = *id;
    Temp->age = *age;
    for (int i = 0; i < MaxSizeName; i++)
    {
        Temp->name[i] = name[i];
    }
    for (int i = 0; i < MaxSizeGender; i++)
    {
        Temp->gender[i] = gender[i];
    }
}
int List_intisEmpty(List_Patients *PL)
{
    return (PL->Head == NULL);
}
int List_intSizeList(List_Patients *PL)
{
    return (PL->size);
}
void List_voidPrintList(List_Patients *PL, int id)
{
    ListPatient *Temp = PL->Head;
    for (int i = 0; i < PL->size; i++)
    {
        if (Temp->id == id)
        {
            system("cls");
            printf(" Patient ID : %d\n", Temp->id);
            printf(" Patient Name : %s\n", Temp->name);
            printf(" Patient age : %d\n", Temp->age);
            printf(" Patient Gender : %s\n", Temp->gender);
        }
        Temp = Temp->Next;
    }
}
int List_voidCheckIDList(List_Patients *PL, int id)
{
    ListPatient *Temp = PL->Head;
    int flaggg = 0;
    for (int i = 0; i < PL->size; i++)
    {
        if (Temp->id == id)
        {
            flaggg++;
            break;
        }
        Temp = Temp->Next;
    }
    return flaggg;
}
void PrintFreeSlots(void)
{
    flag = 0;
    system("cls");
    for (int i = 0; i < MAX; i++)
    {
        switch (i)
        {
        case 0:
            if (Slot[i] == 0)
                printf(" Slot %d From 2pm To 2:30pm is Available\n", i);
            break;
        case 1:
            if (Slot[i] == 0)
                printf(" Slot %d From 2:30pm To 3pm is Available\n", i);
            break;
        case 2:
            if (Slot[i] == 0)
                printf(" Slot %d From 3pm To 3:30pm is Available\n", i);
            break;
        case 3:
            if (Slot[i] == 0)
                printf(" Slot %d From 4pm To 4:30pm is Available\n", i);
            break;
        case 4:
            if (Slot[i] == 0)
                printf(" Slot %d From 4:30pm To 5pm is Available\n", i);
            break;
        }
        if (Slot[i] != 0)
            flag++;
    }
    if (flag == 5)
    {
        system("cls");
        printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
        printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
        printf("  Sorry, All Slots is NOT Available  \n");
        printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
        printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    }
}
void PrintReservationSlots(void)
{
    int flagg = 0;
    for (int i = 0; i < MAX; i++)
    {
        switch (i)
        {
        case 0:
            if (Slot[i] != 0)
            {
                printf(" Slot %d From 2pm To 2:30pm ( Reserved to ID ) %d \n", i, Slot[i]);
            }
            else
            {
                printf(" Slot %d From 2pm To 2:30pm is Available\n", i);
                flagg++;
            }
            break;
        case 1:
            if (Slot[i] != 0)
            {
                printf(" Slot %d From 2:30pm To 3pm ( Reserved to ID ) %d \n", i, Slot[i]);
            }
            else
            {
                printf(" Slot %d From 2:30pm To 3pm is Available\n", i);
                flagg++;
            }
            break;
        case 2:
            if (Slot[i] != 0)
            {
                printf(" Slot %d From 3pm To 3:30pm ( Reserved to ID ) %d \n", i, Slot[i]);
            }
            else
            {
                printf(" Slot %d From 3pm To 3:30pm is Available\n", i);
                flagg++;
            }
            break;
        case 3:
            if (Slot[i] != 0)
            {
                printf(" Slot %d From 4pm To 4:30pm ( Reserved to ID ) %d \n", i, Slot[i]);
            }
            else
            {
                printf(" Slot %d From 4pm To 4:30pm is Available\n", i);
                flagg++;
            }
            break;
        case 4:
            if (Slot[i] != 0)
            {
                printf(" Slot %d From 4:30pm To 5pm ( Reserved to ID ) %d \n", i, Slot[i]);
            }
            else
            {
                printf(" Slot %d From 4:30pm To 5pm is Available\n", i);
                flagg++;
            }
            break;
        }
    }
    if ((flagg != 0) && (flagg != 1) && (flagg != 2) && (flagg != 3) && (flagg != 4))
    {
        system("cls");
        printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
        printf("   There is No Reservations  \n");
        printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    }
}