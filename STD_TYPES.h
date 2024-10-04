
/*=================================================================================*/
/*  @File        : STD_TYPES.h                                                     */
/*  @Description : This file includes STD_TYPES macros                             */
/*  @Author      : Mustafa khaled Elkhokh                                          */
/*  @Date        : 10/9/2024                                                       */
/*  @mail        : mustafaelkhokhy@gmil.com                                        */
/*=================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef STD_TYPES_H
#define STD_TYPES_H

/* unsigned numbers */
typedef unsigned char            u8 ;       // 1 Byte - 255 Bit
typedef unsigned short int       u16 ;      // 2 Byte     +
typedef unsigned long int        u32 ;      // 4 Byte     +
typedef unsigned long long int   u64 ;

/* signed numbers */
typedef signed char             s8 ;         // 1 Byte     - to +
typedef signed short int        s16 ;        // 2 Byte     - to +
typedef signed long int         s32 ;        // 4 Byte     - to +
typedef signed long long int    s64 ;

/* float numbers */
typedef float                   f32 ;       // 4 Byte
typedef double                  f64 ;       // 8 Byte
typedef long double             f128 ;      // 16 Byte


#define MaxSizeName 40
#define MaxSizeGender 10
#define MAX 5

typedef struct listpatient
{
    u16 id, age, slot;
    u8 name[MaxSizeName];
    u8 gender[MaxSizeGender];
    struct listpatient *Next;
} ListPatient;
typedef struct linkedlist
{
    ListPatient *Head;
    u16 size;
} List_Patients;
/* Functions Decleration to List_Patient */

void List_voidInitList(List_Patients *PL);
void List_voidInsertList(List_Patients *PL, u16 *id, u16 *age, u8 *name, u8 *gender, u16 *slot);
void List_voidInsertLast(List_Patients *PL, u16 *id, u16 *age, u8 *name, u8 *gender);
void List_voidReplaceList(List_Patients *PL, u16 *id, u16 *age, u8 *name, u8 *gender, u16 *slot);
void List_voidPrintList(List_Patients *PL, u16 id);
u16 List_intisEmpty(List_Patients *PL);
u16 List_intSizeList(List_Patients *PL);
u16 List_voidCheckIDList(List_Patients *PL, u16 id);
void PrintFreeSlots(void);
void PrintReservationSlots(void);
u16 CheckUniqeID_Slot(u16 *id);

u16 Slot[MAX] = {0, 0, 0, 0, 0};
u16 flag = 0;
u16 id, age, pos, slot, exit_program = 0;

#define NOT_OK 0
#define OK 1
#endif
