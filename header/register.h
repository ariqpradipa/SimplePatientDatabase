int register_staff() {
	
	/*
	fungsi ini berfungsi untuk menambahkan staff
	baru untuk bisa login kedalam sistem
	*/

	system("cls");

	char ID[255], Pass[255];
	char confm;
	
	fflush(stdin);

    // membuka file staff
	FILE *fptr;
    fptr = fopen("data/staff.txt", "a+");
	
	printf(" Selamat Datang Staff Baru!\n");
	printf("============================\n");

	// mengambil input dari user
	printf(" Masukkan ID: "); scanf("%s", &ID);
	printf(" Masukkan Password: "); scanf("%s", &Pass);

    // menulis ke text ke file
    fprintf(fptr, "%s %s\n", ID, Pass);
	
    // tutup file
    fclose(fptr);
	
	printf("\n Apakah masih ada staff yang ingin didaftarkan?(Y/N) "); scanf("%s", &confm);
	if(confm == 'y' || confm == 'Y') {
		register_staff();
	}
	else if(confm == 'n' || confm == 'N') {
		main_menu();	// terdapat dalam header menu.h
	}
	else {
		main_menu();	// terdapat dalam header menu.h
	}
	return 0;
}