/* 
header ini berisikan tentang keperluan login
didalam sistem
*/

int login_page(int x, char* filename) {

    /*
    fungsi ini berguna untuk login kedalam sistem sebagai staff
    dimana diberi 3 kali kesempatan untuk memasukkan ID dan Pass
    jika salah maka akan dibawa kembali ke halaman pertama
    */

    if(x < 3) {
        char string[256];
        char *stripped;
        char *str1;
        char *str2;
        char ID[255], Pass[255];
		
		printf("\n");
        printf(" Sisa Percobaan %d", 3 - x); printf("\n");
        printf("==================="); printf("\n");
        printf(" ID: "); scanf("%s", &ID);          // input ID
        printf(" Password: "); scanf("%s", &Pass);  // input Pass
        fflush(stdin);

        // membuka file "data/staff.txt"
        FILE *txt;
        txt = fopen(filename, "r+");

        /*
        loop membandingkan input ID dan Pass dengan ID dan Pass
        yang terdapat dalam "data/staff.txt"
        */
        while(fgets(string, sizeof(string), txt) != NULL) {

            stripped = strtok(string, "\n");    // mengambil satu line string dalam file
            str1 = strtok(stripped, " ");       // memecah string hingga spasi
            str2 = strtok(NULL, " ");           // memecah sisa string hingga spasi

            // membandingkan input dengan data dalam file
            if(strcmp(str1, ID) == 0 && strcmp(str2, Pass) == 0) {

                fclose(txt);
                return 1;
            }
        }

        x++;
        fclose(txt); // menutup kembali file
        fflush(stdin);
        login_page(x, filename);
    }
    else {

        printf("\n Login Gagal!\n");
        system("pause");
        fflush(stdin);
        main();

    }

}

int admin_login(int x, char* filename) {

    /*
    fungsi ini berfungsi untuk admin login dimana diperlukan
    kontrol admin untuk menghapus staff dalam sistem
    */
        
    if(x < 3) {
        char string[256];
        char *stripped;
        char *str1;
        char *str2;
        char ID[255], Pass[255];

        printf("\nSisa percobaan %d\n", 3 - x);
        printf("ID: "); scanf("%s", &ID);           // input ID
        printf("Password: "); scanf("%s", &Pass);   // input Pass
        fflush(stdin);

        // membuka file "data/admin.txt"
        FILE *txt;
        txt = fopen(filename, "r+");

        /*
        loop membandingkan input ID dan Pass dengan ID dan Pass
        yang terdapat dalam "data/admin.txt"
        */
        while(fgets(string, sizeof(string), txt) != NULL) {

            stripped = strtok(string, "\n");    // mengambil satu line string pada file
            str1 = strtok(stripped, " ");       // memecah string hingga spasi
            str2 = strtok(NULL, " ");           // memecah sisa string hingga spasi

            // membandingkan input ID dan Pass dengan ID dan pass yang ada pada FILE
            if(strcmp(str1, ID) == 0 && strcmp(str2, Pass) == 0) {

                fclose(txt);
                return 1;
            }
        }

        x++;
        fclose(txt); // menutup FILE
        fflush(stdin);
        admin_login(x, filename);
    }
    else {
        
        printf("\n Login Gagal!\n");
        system("pause");
        fflush(stdin);
        main_menu();

    }
    
}