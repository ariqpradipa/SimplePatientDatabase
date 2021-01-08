/*
header ini bersikan semua fungsi yang berkaitan dengan manajemen pasien
seperti menambahkan, menset status menjadi sehat dan melist pasien beserta
dengan statusnya sekarang
*/

int pasien_daftar() {
	
	/* 
	fungsi ini berfungsi untuk menambahkan pasien baru kedalam sistem
	pasien yang di input datanya disini akan disimpan dalam sebuah text file
	yang nantinya dapat diakses kembali untuk memperbarui status pasien
	*/

	system("cls");	// membersihkan console
	
	char nama_depan[20], nama_belakang[20], *jenis_kelamin, *status_pasien;
	int hari_lahir, bulan_lahir, tahun_lahir;
	int input_jk, input_stat;
	
	printf("==========================="); printf("\n");
	printf("  Pendaftaran Pasien Baru  "); printf("\n");
	printf("==========================="); printf("\n \n");
	
	// Input Nama depan dan Nama belakang pasien
	printf(" Nama Depan: "); scanf("%s", &nama_depan);
	printf(" Nama Belakang: "); scanf("%s", &nama_belakang);
	
	// input jenis kelamin pasien
	printf("\n 1. Pria\n 2. Wanita\n");
	printf(" Jenis Kelamin: "); scanf("%d", &input_jk);
	switch(input_jk) {

		case 1: jenis_kelamin = "Pria"; break;
		
		case 2: jenis_kelamin = "Wanita"; break;

		default: printf(" Input Jenis Kelamin salah! Mohon Ulangi.");
		system("pause");
		pasien_daftar();

	}
	
	// input tanggal lahir pasien
	printf("\n Tanggal Lahir:\n");
	printf(" Tanggal (1-31): "); scanf("%d", &hari_lahir);
	printf(" Bulan (1-12): "); scanf("%d", &bulan_lahir);
	printf(" Tahun (XXXX): "); scanf("%d", &tahun_lahir);

	// set status pasien
	printf("\n Status Pasien:\n 1. Sakit\n 2. Dalam Pemantauan\n");
	printf(" Input: "); scanf("%d", &input_stat);
	switch(input_stat) {

		case 1: status_pasien = "Sakit"; break;

		case 2: status_pasien = "Dalam_Pemantauan"; break;

		default: printf(" Input status pasien salah! Mohon Ulangi");
		system("pause");
		pasien_daftar();

	}
	printf("============================="); printf("\n");
	
	// pengecekan ulang data pasien
	printf("\n========PENGECEKAN=========\n");
	
	printf(" Nama Depan: %s\n", nama_depan);
	printf(" Nama Belakang: %s\n", nama_belakang);
	printf(" Jenis Kelamin: %s\n", jenis_kelamin);
	printf(" Tanggal Lahir: %d-%d-%d\n", hari_lahir, bulan_lahir, tahun_lahir);
	printf(" Status: %s\n", status_pasien);

	char confm;
	printf("\n Apakah data sudah benar?(Y/N) "); scanf(" %c", &confm);

	if(confm == 'y' || confm == 'Y') {

		// membuka FILE
		FILE *txt2 = fopen("data/pasien_sakit.txt", "a+");
		// menuliskan data pasien dalam FILE
		fprintf(txt2, "%s %s %s %d %d %d %s\n", nama_depan, nama_belakang, jenis_kelamin, hari_lahir, bulan_lahir, tahun_lahir, status_pasien);	
		// menutup FILE
		fclose(txt2);
		fflush(stdin);

		printf("\n Ingin input data pasien lagi?(Y/N) "); scanf(" %c", &confm);

		if(confm == 'y' || confm == 'Y') {

			pasien_daftar();

		}
		else if(confm == 'n' || confm == 'N') {

			main_menu(); // terdapat dalam header menu.h

		}
		else {

			main_menu(); // terdapat dalam header menu.h

		}
	} 
	
	else if(confm == 'n' || confm == 'N') {

		printf("\n Mohon Masukkan Ulang Seluruh Data Pasien Dengan Benar!");
		system("pause");
		pasien_daftar();

	}

	else {

		printf("\n Input yang dimasukkan salah! Mohon Ulangi Kembali!");
		system("pause");
		pasien_daftar();

	}

}

typedef struct PointerString {

	char *str;	// pointer string untuk menyimpan potongan string

} pointerstring;

int pasien_sembuh() {

	/*
	fungsi ini berfungsi untuk menambahkan pasien Covid-19 baru kedalam sistem
	yang nanti akan disimpan kedalam FILE yang sudah di siapkan. data yang 
	ditambahkan di dalam fungsi ini dapat diakses dengan melihat list pasien
	*/

	system("cls"); // membersihkan console

	pointerstring string[5];
	char string_pasien[255];
	char *str2;
	char *stripped;
	int choice;
	int line = 0, i = 0;

	FILE *txt = fopen("data/pasien_sakit.txt", "r+");	// membuka FILE "data/pasien_sakit.tct"
	FILE *txt2 = fopen("data/pasien_sembuh.txt", "a+");	// membuka FILE "data/pasien_sembuh.txt" 
	FILE *txt_temp = fopen("data/temp.txt", "a+");		// membuka FILE "data/temp.txt"

	/*
	loop untuk menampilkan keseluruhan pasien yang sedang sakit 
	ke layar console untuk kemudian nanti dipilih oleh user
	*/
	while(fgets(string_pasien, sizeof(string_pasien), txt) != NULL) {

		stripped = strtok(string_pasien, "\n"); // menyimpan satu line string dalam FILE
		string[0].str = strtok(stripped, " ");	// menyimpan string potongan pertama dari stripped sampai spasi pertama
		for(i = 1; i < 6; i++) {				// loop untuk menyimpan potongan string yang akan tersimpan dalam array struct

			string[i].str = strtok(NULL, " ");

		}
		str2 = strtok(NULL, " ");				// menyimpan string potongan terakhir

		// menampilkan data pasien ke console
		printf("       Pasien ke-%d        ", line+1); printf("\n");
		printf("==========================="); printf("\n");
		printf(" Nama: %s %s\n", string[0].str, string[1].str);
		printf(" Jenis Kelamin: %s\n", string[2].str);
		printf(" Tanggal Lahir: %s-%s-%s\n", string[3].str, string[4].str, string[5].str);
		printf(" Status: %s\n", str2);
		printf("\n");
		line++;
	}

	printf(" Masukkan 0 untuk keluar\n");
	printf(" Ganti Status Pasien Ke: "); scanf("%d", &choice);
	fclose(txt);					 			// menutup FILE
	txt = fopen("data/pasien_sakit.txt", "a+");	// membuka kembali "data/pasien_sakit.txt" 
	line = 0;
	if(choice == 0) {

		fclose(txt);
		fflush(stdin);
		main_menu(); // terdapat dalam header menu.h

	}
	else {

		/*
		loop untuk menuliskan isi dari pasien_sakit kedalam temp dan pasien
		yang dipilih akan masuke kedalam pasien_sembuuh
		*/
		while(fgets(string_pasien, sizeof(string_pasien), txt) != NULL) {

			line++;
			if(line == choice) {

				stripped = strtok(string_pasien, "\n");
				string[0].str = strtok(stripped, " ");
				for(i = 1; i < 6; i++) {
					string[i].str = strtok(NULL, " ");

				}
				fprintf(txt2, "%s %s %s %s %s %s Sembuh\n", string[0].str, string[1].str, string[2].str, string[3].str, string[4].str, string[5].str);
				continue;

			}
			else {

				fprintf(txt_temp, "%s", string_pasien);

			}
		}
		fclose(txt);		// menutup FILE
		fclose(txt2);		// menutup FILE
		fclose(txt_temp);	// menutup FILE
		remove("data/pasien_sakit.txt");					// menghapus FILE pasien_sakit
		rename("data/temp.txt", "data/pasien_sakit.txt");	// merename temp menjadi pasien sakit

		char confm;
		printf(" Apakah ingin mengubah status pasien lagi?(Y/N) "); scanf(" %c", &confm);

		if(confm == 'y' || confm == 'Y') {

			fflush(stdin);
			pasien_sembuh();

		}
		else if(confm == 'n' || confm == 'N') {

			fflush(stdin);
			main_menu(); // terdapat hedaer menu.h

		}
		else {
			
			printf(" Anda akan diarahkan ke main menu kembali");
			system("pause");
			fflush(stdin);
			main_menu(); // terdapat dalam header menu.h

		}
	}
}

int list_pasien() {

	/*
	fungsi ini berfungsi untuk menampilkan seluruh list pasien yang ada
	dalam sistem. data yang ditampilkan akan berupa nama, jenis kelamin,
	dan statusnya sekarang
	*/
	
	system("cls");
	fflush(stdin);
	
	pointerstring string[5];
   	char sakit[255], sehat[255];
	char *str2;
	char *stripped;
	int line = 0, i = 0;
	
	FILE *fp = fopen("data/pasien_sakit.txt", "r");		// membuka FILE pasien_sakit
	FILE *fp2 = fopen("data/pasien_sembuh.txt", "r");	// membuka FILE pasien_sembuh
	
	// loop untuk menampilkan list pasien yang sakit
	while(fgets(sakit, sizeof(sakit), fp) != NULL) {

		stripped = strtok(sakit, "\n");			// menyimpan satu line string dalam FILE
		string[0].str = strtok(stripped, " ");	// menyimpan string potongan pertama dari stripped sampai spasi pertama
		for(i = 1; i < 6; i++) {				// loop untuk menyimpan potongan string yang akan tersimpan dalam array struct

			string[i].str = strtok(NULL, " ");

		}
		str2 = strtok(NULL, " ");

		printf("       Pasien ke-%d        ", line+1); printf("\n");
		printf("==========================="); printf("\n");
		printf(" Nama: %s %s\n", string[0].str, string[1].str);
		printf(" Jenis Kelamin: %s\n", string[2].str);
		printf(" Status: %s\n", str2);
		printf("\n");
		line++;

	}
	
	// loop untuk menampilakn list pasien yang sehat
	while(fgets(sehat, sizeof(sehat), fp2) != NULL) {

		stripped = strtok(sehat, "\n");			// menyimpan satu line string dalam FILE
		string[0].str = strtok(stripped, " ");	// menyimpan string potongan pertama dari stripped sampai spasi pertama
		for(i = 1; i < 6; i++) {				// loop untuk menyimpan potongan string yang akan tersimpan dalam array struct

			string[i].str = strtok(NULL, " ");

		}
		str2 = strtok(NULL, " ");

		printf("       Pasien ke-%d        ", line+1); printf("\n");
		printf("==========================="); printf("\n");
		printf(" Nama: %s %s\n", string[0].str, string[1].str);
		printf(" Jenis Kelamin: %s\n", string[2].str);
		printf(" Status: %s\n", str2);
		printf("\n");
		line++;

	}
	fclose(fp2);	// menutup FILE
	fclose(fp);		// menutup FILE
	fflush(stdin);
	
	system("pause");
    main_menu(); 	// terdapat dalam header menu.h
}