int manage_staff() {
    
    /*
    fungsi ini berfungsi untuk mengatur staff yang terdaftar pada sistem
    fungsi ini mengatur pendaftaran staff baru dan penghapusan staff
    yang telah terdaftar dalam sistem
    */
    
    system("cls"); // membersihak console

    int inp;

    printf("     STAFF MANAGEMENT   \n");
    printf("========================\n");

    printf(" 1. Tambah Staff\n 2. Hapus Staff\n 3. Help\n 4. Back\n Input: "); scanf("%d", &inp);

    switch(inp) {
		
        case 1: {

            fflush(stdin);
            register_staff(); // terdapat dalam header register.h

        }

        case 2: {

            system("cls");
            printf("==================="); printf("\n");
            printf("    ADMIN LOGIN    "); printf("\n");
            printf("==================="); printf("\n");
            
            if(!admin_login(0, "data/admin.txt")) { // masuk ke admin login page

                fflush(stdin);
                main_menu();

            }
           if(1) {                                  // jika return 1 makan akan lanjut ke hapus_staff

                fflush(stdin);
                hapus_staff();

           }
           break;

        }

        case 3: {

            printf("\n");
            printf("=================================================="); printf("\n");
            printf("                      HELP                        "); printf("\n");
            printf("=================================================="); printf("\n \n");
            printf(" Staff bisa didaftarkan oleh staff lainnya tetapi\
            \n menghapus staff dari sistem hanya dapat dilakukan oleh\
            \n admin saja."); printf("\n");
            printf("=================================================="); printf("\n");
            system("pause");
            fflush(stdin);
            manage_staff();
            
        }
		
		case 4: {

			fflush(stdin);
			main_menu();
			break;

		}
		
    	default: {

           printf(" Mohon Masukkan Input Yang Benar!\n");
           system("pause");
           fflush(stdin);
           manage_staff();

       }
   }

}

int hapus_staff() {

    /*
    fungsi ini berfungsi untuk menghapus staff yang sudah terdaftar dalam sistem
    */

    system("cls");

    char string_staff[255], string_temp[255];
    char *str1, *str2;
    char *stripped;
    int choice;
    int line = 0, i = 0;

    // membuka file staff.txt dan temp_staff.txt
    FILE *txt = fopen("data/staff.txt", "r+");
    FILE *txt_temp = fopen("data/temp_staff.txt", "a+");
    system("attrib +h data/temp_staff.txt"); // hide file temp_staff

    // menampilkan isi file dengan loop while
    while(fgets(string_staff, sizeof(string_staff), txt) != NULL) {
        
        stripped = strtok(string_staff, "\n");
        str1 = strtok(stripped, " ");

        printf(" Staff ke-%d  ", line+1); printf("\n");
        printf("=============="); printf("\n");
        printf(" ID: %s\n", str1);
        printf("\n");
        line++;
    }

    printf(" Masukkan 0 untuk keluar\n");
    printf(" Hapus Staff Ke: "); scanf("%d", &choice);

    if(choice == 1) {

        // admin tidak dapat dihapus karena itu adalah login default
        printf("\n TIDAK DAPAT MENGHAPUS DEFAULT STAFF!\n");
        system("pause");
        fclose(txt);
        fflush(stdin);
        hapus_staff();

    }
    else if(choice == 0) {
    	
        fclose(txt);
        fflush(stdin);
        main_menu();
        
    }
    else {

        fclose(txt); // menutup file staff.txt
        txt = fopen("data/staff.txt", "a+"); // membuka kembali file staff.txt
        line = 0;

        // menuliskan isi staff.txt kedalam temp_staff.txt kecuali staff yang dihapus
        while(fgets(string_staff, sizeof(string_staff), txt) != NULL) {

            line++;
            if(line == choice) {
            	
                continue;
                
            }
            else {
            	
                fprintf(txt_temp, "%s", string_staff);
                
            }
        }
        // menutup keduda file
        fclose(txt);
        fclose(txt_temp);
        
        remove("data/staff.txt");
        rename("data/temp_staff.txt", "data/staff.txt");
        system("attrib +h data/staff.txt"); // hide file staff.txt


        char confm;
	    printf("\n Apakah anda ingin menghapus staff lagi?(Y/N) "); scanf(" %c", &confm);

	    if(confm == 'y' || confm == 'Y') {

		    fflush(stdin);
		    hapus_staff();
		    
	    }

	    else if(confm == 'n' || confm == 'N') {

		    fflush(stdin);
		    main_menu();
		    
	    }

	    else {
	    	
		    printf(" Anda akan diarahkan ke main menu kembali");
		    system("pause");
		    fflush(stdin);
		    main_menu();
		    
	    }
    }
}
