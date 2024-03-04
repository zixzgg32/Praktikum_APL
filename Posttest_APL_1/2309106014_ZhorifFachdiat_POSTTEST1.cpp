#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void konversiUang(double uang, string currency){
	double konversi1,konversi2,konversi3;
	if(uang>=0){
		if(currency=="rupiah"){
			konversi1=uang/15701.95;
			konversi2=uang/17043.68;
			konversi3=uang/104.61;
			cout<<"Nominal =  "<<fixed<<setprecision(2)<<uang<<" IDR"<<endl;
			cout<<"Konversi ke Dollar = "<<fixed<<setprecision(2)<<konversi1<<" USD"<<endl;
			cout<<"Konversi ke Euro   = "<<fixed<<setprecision(2)<<konversi2<<" EUR"<<endl;
			cout<<"Konversi ke Yen    = "<<fixed<<setprecision(2)<<konversi3<<" JPY"<<endl;
		}else if(currency=="dollar"){
			konversi1=uang/0.000064;
			konversi2=uang/1.09;
			konversi3=uang/0.0067;
			cout<<"Nominal =  "<<fixed<<setprecision(2)<<uang<<" USD"<<endl;
			cout<<"Konversi ke Rupiah = "<<fixed<<setprecision(2)<<konversi1<<" IDR"<<endl;
			cout<<"Konversi ke Euro   = "<<fixed<<setprecision(2)<<konversi2<<" EUR"<<endl;
			cout<<"Konversi ke Yen    = "<<fixed<<setprecision(2)<<konversi3<<" JPY"<<endl;
		}else if(currency=="euro"){
			konversi1=uang/0.000059;
			konversi2=uang/0.92;
			konversi3=uang/0.0061;
			cout<<"Nominal =  "<<fixed<<setprecision(2)<<uang<<" EUR"<<endl;
			cout<<"Konversi ke Rupiah = "<<fixed<<setprecision(2)<<konversi1<<" IDR"<<endl;
			cout<<"Konversi ke Dollar = "<<fixed<<setprecision(2)<<konversi2<<" USD"<<endl;
			cout<<"Konversi ke Yen    = "<<fixed<<setprecision(2)<<konversi3<<" JPY"<<endl;
		}else {
			konversi1=uang/0.0096;
			konversi2=uang/150.09;
			konversi3=uang/162.93;
			cout<<"Nominal =  "<<fixed<<setprecision(2)<<uang<<" JPY"<<endl;
			cout<<"Konversi ke Rupiah = "<<fixed<<setprecision(2)<<konversi1<<" IDR"<<endl;
			cout<<"Konversi ke Dollar = "<<fixed<<setprecision(2)<<konversi2<<" USD"<<endl;
			cout<<"Konversi ke Euro   = "<<fixed<<setprecision(2)<<konversi3<<" EUR"<<endl;
		}
	}else{
		cout<<"\nNominal terlalu rendah untuk di konversi!!\n"<<endl;
	}
}

int main(){
	bool login,ulang;
	ulang=true;
	int gagalLogin=0;
	double uang;
	string namaUser,nimUser,pilihan,currency;
	cout<<"Selamat datang di program menkonversi mata uang\nSilahkan melakukan login terlebih dahulu\n"<<endl;
	while(login==false && gagalLogin<3){
		cout<<"Masukkan nama anda: ";
		getline(cin,namaUser);
		cout<<"Masukkan NIM anda : ";
		getline(cin,nimUser);
		if (namaUser=="Zhorif Fachdiat"&&nimUser=="2309106014"){
			login=true;
		}else{
			gagalLogin++;
		}	
	}
	if(login==true){
		while(ulang==true){
			cout<<"\nMENU UTAMA\n1. Konversi Rupiah\n2. Konversi Dollar\n3. Konversi Euro\n4. Konversi Yen\n5. EXIT"<<endl;
			cout<<"Pilihan = ";
			cin>>pilihan;
			if (pilihan=="1"){
				cout<<"\nKonversi Rupiah\nMasukkan nominal yang ingin di konversi: ";
				cin>>uang;
				konversiUang(uang,"rupiah");
			}else if (pilihan=="2"){
				cout<<"\nKonversi Dollar\nMasukkan nominal yang ingin di konversi: ";
				cin>>uang;
				konversiUang(uang,"dollar");
			}else if (pilihan=="3"){
				cout<<"\nKonversi Euro\nMasukkan nominal yang ingin di konversi: ";
				cin>>uang;
				konversiUang(uang,"euro");
			}else if (pilihan=="4"){
				cout<<"\nKonversi Yen\nMasukkan nominal yang ingin di konversi: ";
				cin>>uang;
				konversiUang(uang,"yen");
			}else if (pilihan=="5"){
				cout<<"\nKeluar Program";
				ulang=false;
			}else{
				cout<<"\nPilihan tidak ditemukan!!\n";
			}
		}
	}else{
		cout<<"\nGagal melakukan Login!!";
	}
	cin.get();
	return 0;
}
