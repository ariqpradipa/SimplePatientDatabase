// Kelompok Manggis
// Proyek Akhir Semester 1 Pemrograman Dasar Universitas Indonesia 2020
// PROGRAM DATABASE PASIEN COVID-19 RSUI

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// semua header yang di include disini dapat dilihat di folder header
#include "header/login.h"
#include "header/menu.h"
#include "header/pasien_dat.h"
#include "header/staff_man.h"
#include "header/register.h"

/*
DEFAULT STAFF LOGIN
ID: xids
pass: xpass
*/

/*
ADMIN LOGIN
ID: admin
pass: manggis1234
*/

int main() {
	
	system("cls");

    int fspage = 0;
    printf("==============================="); printf("\n");
    printf(" DATABASE PASIEN COVID-19 RSUI "); printf("\n");
    printf("==============================="); printf("\n \n");

    printf(" 1. Login    				   "); printf("\n");
    printf(" 2. Help    				   "); printf("\n");
    printf("==============================="); printf("\n");
    printf(" + Input: "); scanf("%d", &fspage);

    switch(fspage) {

        case 1: {

            system("cls");
            printf("==================="); printf("\n");
            printf("    STAFF LOGIN    "); printf("\n");
            printf("==================="); printf("\n");

            if(!login_page(0, "data/staff.txt")) {  // masuk kedalam staff login page
                fflush(stdin);
                main();
            }
            if(1) {                                 // jika return 1 maka akan masuk kedalam main_menu
                main_menu();
            }
            break;

        } 

        case 2: {

            printf("\n");
            printf("============================================================"); printf("\n");
			printf("                            HELP                            "); printf("\n");
			printf("============================================================"); printf("\n \n");
            printf(" Program ini berfungsi untuk mendata banyaknya pasien\
            \n dalam suatu rumah sakit. Program ini dapat menset\
            \n status pasien sakit, sehat, dan dalam pemantauan.\n");
            printf("============================================================"); printf("\n");
            system("pause");
            system("cls");
            fflush(stdin);
            main();

        }
        
        default : {

            printf("Masukkan pilihan yang benar!\n");
            system("pause");
            fflush(stdin);
            system("cls");
            main();

        }
    }
}
