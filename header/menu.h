int main_menu() {

    /* 
	function main_menu adalah tampilan utama untuk user berinteraksi dengan program
	disini user dapat memilih salah satu dari beberapa pilihan yang ada untuk menambahkan,
	mengurangkan, dan melihat list pasien.
	*/

    system("cls");	// membersihkan console
    fflush(stdin);	// membersihkan standard input
    int mput = 0;
    
    system("cls");
    printf("========================="); printf("\n");
    printf("        MAIN MENU        "); printf("\n");
    printf("========================="); printf("\n \n");
    
	printf(" 1. Daftar Pasien Baru\n");
	printf(" 2. Ganti Status Pasien\n");
	printf(" 3. List Pasien\n");
	printf(" 4. Manage Staff\n");
	printf(" 5. Help\n");
	printf(" 6. LOGOUT\n");
	printf("========================="); printf("\n");
	printf("+ Input: "); scanf("%d", &mput);	// input pilihan menu
    
    switch(mput) {
    	
    	case 1: {

			// terdapat dalam header pasien_dat.h
    		pasien_daftar();
			break;

		}
		
		case 2: {

			// terdapat dalam header pasien_dat.h
			pasien_sembuh();
			break;

		}

		case 3: {

			// terdapat dalam header pasien_dat.h
			list_pasien();
			break;

		}
		
		case 4: {

			// terdapat dalam header staff_man.h
			manage_staff();
			break;

		}
		
		case 5: {

			printf("\n");
			printf("================================================================================="); printf("\n");
			printf("                                     HELP                                        "); printf("\n");
			printf("================================================================================="); printf("\n \n");
			
			printf(" -Daftar Pasien Baru: Menambahkan pasien Covid-19 baru\n");
			printf(" -Ganti Status Pasien: Mengganti status pasien menjadi sembuh\n");
			printf(" -List Pasien: Melihat keseluruhan pasien Covid-19 yang pernah dirawat disini\n");
			printf(" -Manage Staff: Mengatur staff yang terdaftar dalam sistem\n");
			printf("================================================================================="); printf("\n");
			system("pause");
			fflush(stdin);
			main_menu(); // terdapat dalam header menu.h
			break;

		}
		
		case 6: {

			fflush(stdin);
			main();	// terdapat dalam main.c
			break;

		}

		default : {

			printf("MOHON MASUKKAN PILIHAN YANG BENAR!\n");
			system("pause");
			main_menu(); // terdapat dalam header menu.h
			break;

		}
	}
	
    return 0;
}