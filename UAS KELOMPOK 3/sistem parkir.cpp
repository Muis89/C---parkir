#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include <windows.h>

using namespace std;
struct trx //membuat struktur trx
{
	int m,type,pil,status,lama,biaya;
	char plat[100];
	char tgl_masuk[100];

}trx[100]; //deklarasikan

main(){
	int pil,a,b,total;
	char ch, temp,yn;
	int m = -1; 
	int d = -1; 
	
	login:
	string user = "";
	string pass = "";
		cout<<" \n\n\n \t\t\t ---- LOGIN SISTEM PARKIR ----  \t\t\t\t \n";
		cout<<"\n \t\t\t Username : ";
		cin>>user;
		cout<<"\n \t\t\t Password : ";
		ch = _getch();
	    while(ch != 13){ //karakter 13
	    pass.push_back(ch);
	    cout << '*';
	    ch = _getch();
	    }
	    if(user == "Muis" && pass == "123"){
			cout << "\n\n Anda berhasil login. \n" << endl;
			system("pause");
			system("cls");
			goto menu;
		}else{
			cout<<"\n\n Password Anda Salah \n";
	   	    system("pause");
	   	    system("cls");
		 	goto login;
		}
	menu:
	cout<<"---- Sistem Parkir  ----"<<endl;
    cout<<"-------- Menu ----------\n";
    cout<<" 1. Transaksi	       \n";
    cout<<" 2. Laporan 		       \n";
    cout<<" 3. Exit                \n";
    cout<<"------------------------\n";
    cout<<"Masukan Pilihan anda[ 1 s.d. 3 ] = ";
	cin>>pil;
	
	system("cls");
	if(pil == 1)
	{
		trxmasuk:
		m++;
		cout<<"\n\n \t\t\t ------- FORM TRANSAKSI MASUK ------- \t\t\t";
		cout<<"\n Masukkan Plat : ";
		cin>>trx[m].plat;
		//scanf("%s", &trx[m].plat, &temp);
		cout<<"\n type kendaraan : \n  1. motor \n  2. mobil \n";
		cout<<" pilih type kendaraan [1 / 2 ] : ";
		cin>>trx[m].type;
		cout<<" Lama Parkir	: ";
		cin>>trx[m].lama;
		//sscanf(ctime(&waktu), "%s", &trx[m].tgl_masuk, &temp);
		
		time_t waktu;	
		time(&waktu);
		strcpy(trx[m].tgl_masuk,ctime(&waktu));
		
			cout<<" ++++++++++++++++++++++++++++++++ \n";
			cout<<" + Plat  	 : "<<trx[m].plat<<endl;
			cout<<" + Type  	 : ";
			
			if(trx[m].type == 1){
				cout<<"motor";
			}
			if(trx[m].type == 2){
				cout<<"mobil";
			}
			cout<<endl;
			cout<<" + Lama Parkir \t : "<<trx[a].lama<<" jam";
			cout<<endl;
			cout<<" + Biaya 	 : ";
			if(trx[m].type == 1){
				if(trx[m].lama>=1 && trx[m].lama<6){
					trx[m].biaya = trx[m].lama * 2000;		
				}else{
					trx[m].biaya = 12000;
				}
			}
			if(trx[m].type == 2){
				if(trx[m].lama>=1 && trx[m].lama<6){
					trx[m].biaya = trx[m].lama * 4000;		
				}else{
					trx[m].biaya = 24000;
				}
			}
			cout<<trx[m].biaya;
			cout<<endl;
			cout<<" + Date		 : "<<trx[m].tgl_masuk;
			cout<<" ++++++++++++++++++++++++++++++++ \n";
	 
		cout<<" Tambah Lagi ? (y/n) :";cin>>yn;
		
		if(yn == 'y'||yn == 'Y'){
			system("pause");
			system("cls");
			goto trxmasuk;
		}else if(yn == 'n' || yn == 'N'){
			cout << "\n\n Data Berhasil Disimpan \n" << endl;
			system("pause");
			system("cls");
			goto menu;
		}else{
			system("pause");
			system("cls");
			goto trxmasuk;
		}
	}
	else if(pil == 2)
	{
		laporan:
			system("cls");
			cout<<"\n"<<endl;
			cout<<"\t\t\t ------- FORM LAPORAN ------- \t\t\t";
		for(b=0;b<=m;b++){
			if(trx[b].type == 1){
				if(trx[b].lama>=1 && trx[b].lama<6){
					trx[b].biaya = trx[b].lama * 2000;		
				}else{
					trx[b].biaya = 12000;
				}
			}
			if(trx[b].type == 2){
				if(trx[b].lama>=1 && trx[b].lama<6){
					trx[b].biaya = trx[b].lama * 4000;		
				}else{
					trx[b].biaya = 24000;
				}
			}
			total = total+trx[b].biaya;
		}
			cout<<"\n\n Pendapatan : "<<total<<endl;
			cout<<endl;
		for(a=0;a<=m;a++){
			cout<<" ++++++++++++++++++++++++++++++++ \n";
			cout<<" + Plat  	  : "<<trx[a].plat<<endl;
			cout<<" + Type  	  : ";
			
			if(trx[a].type == 1){
				cout<<"motor";
			}
			if(trx[a].type == 2){
				cout<<"mobil";
			}
			
			cout<<endl;
			cout<<" + Lama Parkir \t  : "<<trx[a].lama<<" jam";
			cout<<endl;
			cout<<" + Biaya 	  : ";
			if(trx[a].type == 1){
				if(trx[a].lama>=1 && trx[a].lama<6){
					trx[a].biaya = trx[a].lama * 2000;		
				}else{
					trx[a].biaya = 12000;
				}
			}
			if(trx[a].type == 2){
				if(trx[a].lama>=1 && trx[a].lama<6){
					trx[a].biaya = trx[a].lama * 4000;		
				}else{
					trx[a].biaya = 24000;
				}
			}
			cout<<trx[a].biaya;
			cout<<endl;
			cout<<" + Date		  : "<<trx[a].tgl_masuk;
			cout<<" ++++++++++++++++++++++++++++++++ \n\n";
			
		}
			system("pause");
			system("cls");
			goto menu;
	}
	else if(pil == 3)
	{
		cout<<"\n\n -- Anda Telah Logout -- \n\n";
		system("pause");
		system("cls");
		goto login;
	}
	else
	{
		cout<<"\n\n -- pilihan tidak tersedia -- \n\n";
		system("pause");
		system("cls");
		goto menu;	
	} 
		
}
