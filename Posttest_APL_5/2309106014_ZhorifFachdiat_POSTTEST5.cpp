#include <iostream>
#include <string>
#include <limits>
using namespace std;

//	program CRUD daftar item dalam game Risk Of Rain 2
//	Milik Zhorif Fachdiat dengan NIM 2309106014 dari kelas praktikum A1'23

int gagalLogin=0,pilihanJenisItem,pilihanSubMenu;
string namaUser,nimUser;
bool ulang=true,berhasilLogin=false;

bool login(){
	while(berhasilLogin==false && gagalLogin<3){	
		cout<<"Masukkan nama anda: ";
		getline(cin,namaUser);
		cout<<"Masukkan NIM anda : ";
		getline(cin,nimUser);
		if (namaUser=="Zhorif Fachdiat"&&nimUser=="2309106014"){
			berhasilLogin=true;
		}else{
			gagalLogin++;
		}	
	}
	return berhasilLogin;
}

struct items{
	string nama;
	string stack;
	string unlocked;
};
struct itemROR2{
	string rarityItems;
	int jumlahItems;
	items dataItems[50];
};

itemROR2 chestsItems[3] = {
	{"Common Items",29,{{"Armor-Piercing Rounds","Linear","Advancement"}, {"Backup Magazine","Linear","Flawless"}, {"Bison Steak","Linear","Default"}, {"Bundle of Fireworks","Linear","...Maybe One More"}, {"Bustling Fungus","Linear","Default"}, {"Cautious Slug","Linear","Default"}, {"Crowbar","Linear","The Basics"}, {"DelicLinearate Watch","Linear","Survivors of the Void"}, {"Energy Drink","Linear","Default"}, {"Focus Crystal","Linear","Default"}, {"Gasoline","Linear","Default"}, {"Lens-Maker's Glasses","Linear","Default"}, {"Medkit","Linear","Default"}, {"Mocha","Linear","Survivors of the Void"}, {"Monster Tooth","Linear","Default"}, {"Oddly-shaped Opal","Linear","Survivors of the Void"}, {"Paul's Goat Hoof","Linear","Is This Bugged?"}, {"Personal Shield Generator","Linear","Default"}, {"Power Elixir","-","Survivors of the Void"}, {"Repulsion Armor Plate","Linear","Default"}, {"Roll of Pennies","Linear","Survivors of the Void"}, {"Rusted Key","-","Keyed Up"}, {"Soldier's Syringe","Linear","Default"}, {"Sticky Bomb","Linear","Default"}, {"Stun Grenade","Hyperbolic","Default"}, {"Topaz Brooch","Linear","Default"}, {"Tougher Times","Linear","Default"}, {"Tri-Tip Dagger","Linear","Default"}, {"Warbanner","Linear","Default"}}},
	{"Uncommon Items",30,{{"AtG Missile Mk.1","Linear","Default"}, {"Bandolier","Special","Default"}, {"Berzerker's Pauldron","Linear","Glorious Battle"}, {"Chronobauble","Linear","Default"}, {"Death Mark","Linear","Default"}, {"Fuel Cell","Linear Exponential","Experimenting"}, {"Ghor's Tome","Linear","Default"}, {"Harvester's Scythe","Linear","Prismatically Aligned"}, {"Hopoo Feather","Linear","Default"}, {"Hunter's Harpoon","Linear","Survivors of the Void"}, {"Ignition Tank","Linear","Survivors of the Void"}, {"Infusion","Linear","Slaughter"}, {"Kjaro's Band","Linear","Death Do Us Part"}, {"Leeching Seed","Linear","Default"}, {"Lepton Daisy","Linear","Default"}, {"Old Guillotine","Hyperbolic","Cut Down"}, {"Old War Stealthkit","Exponential","Default"}, {"Predatory Instincts","None Linear","Rapidfire"}, {"Razorwire","Linear","Default"}, {"Red Whip","Linear","Default"}, {"Regenerating Scrap","-","Survivors of the Void"}, {"Rose Buckler","Linear","Default"}, {"Runald's Band","Linear","Death Do Us Part"}, {"Shipping Request Form","Special","Survivors of the Void"}, {"Shuriken","Linear","Survivors of the Void"}, {"Squid Polyp","Linear","Automation Activation"}, {"Ukulele","Linear","Default"}, {"War Horn","Linear","Warmonger"}, {"Wax Quail","Linear","Going Fast Recommended"}, {"Will-o'-the-wisp","Linear","Default"}}},
	{"Legendary Items",27,{{"57 Leaf Clover","Linear","The Long Road"}, {"Aegis","Linear","Default"}, {"Alien Head","Exponential","Default"}, {"Ben's Raincoat","None Linear","Survivors of the Void"}, {"Bottled Chaos","Linear","Survivors of the Void"}, {"Brainstalks","Linear","Deicide"}, {"Brilliant Behemoth","Linear","Default"}, {"Ceremoniak Dagger","Linear","Default"}, {"Defensive Microbots","Linear","Default"}, {"Dio's Best Friend","Linear","The Lone Survivor"}, {"Frost Relic","Linear","Default"}, {"H3AD-5T v2","Reciprocal","Default"}, {"Happiest Mask","Linear","Default"}, {"Hardlight Afterburner","Linear","Default"}, {"Interstellar Desk Plant","Linear","Default"}, {"Laser Scope","Linear","Survivors of the Void"}, {"N'kuhana's Opinion","Linear","Her Concepts"}, {"Pocket I.C.B.M","None Linear","Survivors of the Void"}, {"Rejuvenation Rack","Linear","Naturopath"}, {"Resonance Disc","Linear","Default"}, {"Sentient Meat Hook","Linear","Deja Vu?"}, {"Shattering Justice","Linear","Default"}, {"Soulbound Catalyst","Linear","Newtist"}, {"Spare Drone Parts","Linear","Survivors of the Void"}, {"Symbiotic Scorpion","Linear","Survivors of the Void"}, {"Unstable Tesla Coil","Linear","Macho"}, {"Wake of Vultures","Linear","Default"}}}
};

void tampilkanDataItem(items *item) {
    cout << item->nama << " (" << item->stack << ")" << endl;
    cout << "    Cara Mendapatkan: " << item->unlocked << endl;
}

void tampilkanDaftarItems(itemROR2 &chest) {
    cout << "\nDaftar Items pada " << chest.rarityItems << " Chest:" << endl;
    for (int i = 0; i < chest.jumlahItems; ++i) {
        cout << i + 1 << ". ";
        tampilkanDataItem(&chest.dataItems[i]);
        cout << endl;
    }
}

void tambahItem(itemROR2 &chest) {
    cout << "\nTambah Item" << endl;
    cout << "Masukkan Nama Item : ";
    getline(cin, chest.dataItems[chest.jumlahItems].nama);

    cout << "Masukkan Jenis Stack Item : ";
    getline(cin, chest.dataItems[chest.jumlahItems].stack);

    cout << "Masukkan Unlocked Item : ";
    getline(cin, chest.dataItems[chest.jumlahItems].unlocked);

    chest.jumlahItems++;
    cout << "Item berhasil ditambahkan." << endl;
}

void editItem(itemROR2 &chest) {
    cout << "\nMasukkan nomor item yang ingin diedit: ";
    int nomor;
    cin >> nomor;
    cin.ignore();
    if (cin.fail()){
        	cout << "Input tidak valid. Harap masukkan angka." << endl;
	        cin.clear();
	        cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} else {
	    if (nomor >= 1 && nomor <= chest.jumlahItems) {
	        items& item = chest.dataItems[nomor - 1];
	
	        cout << "1. Edit Nama Item (sekarang: " << item.nama << ")" << endl;
	        cout << "2. Edit Stack (sekarang: " << item.stack << ")" << endl;
	        cout << "3. Edit Unlocked (sekarang: " << item.unlocked << ")" << endl;
	        cout << "Pilihan: ";
	        int pilihan;
	        cin >> pilihan;
	        cin.ignore(); 
	        if (cin.fail()){
	        	cout << "Input tidak valid. Harap masukkan angka." << endl;
		        cin.clear();
		        cin.ignore(numeric_limits<streamsize>::max(), '\n');
			} else {
				switch (pilihan) {
		            case 1: {
		                cout << "Masukkan Nama Item Baru: ";
		                getline(cin, item.nama);
		                break;
		            }
		            case 2: {
		                cout << "Masukkan Stack Baru: ";
		                getline(cin, item.stack);
		                break;
		            }
		            case 3: {
		                cout << "Masukkan Unlocked Baru: ";
		                getline(cin, item.unlocked);
		                break;
		            }
		            default: {
		                cout << "Pilihan tidak valid." << endl;
		                return;
		            }
				}
	        }
	        cout << "Item berhasil diubah." << endl;
	    }
	    else {
	        cout << "Nomor item tidak valid." << endl;
	    }
	}
}

void hapusItem(itemROR2 &chest) {
    cout << "\nMasukkan nomor item yang ingin dihapus: ";
    int nomor;
    cin >> nomor;
    cin.ignore(); 
    if (cin.fail()){
        	cout << "Input tidak valid. Harap masukkan angka." << endl;
	        cin.clear();
	        cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} else {
		if (nomor >= 1 && nomor <= chest.jumlahItems) {
	        for (int i = nomor - 1; i < chest.jumlahItems - 1; ++i) {
	            chest.dataItems[i] = chest.dataItems[i + 1];
	        }
	        chest.jumlahItems--;
	        cout << "Item berhasil dihapus." << endl;
	    }
	    else {
	        cout << "Nomor item tidak valid." << endl;
	    }
	}
}

int main() {
    cout << "Selamat datang di program Daftar item dalam game Risk Of Rain 2\nSilahkan melakukan login terlebih dahulu\n" << endl;
    berhasilLogin = login();
    if (berhasilLogin == true) {
        while (ulang) {
            cout << "\nMenu:\n1. Common Items\n2. Uncommon Items\n3. Legendary Items\n4. Keluar"<<endl;
            cout << "Pilihan: ";
            cin >> pilihanJenisItem; 
            cin.ignore();

            if (pilihanJenisItem >= 1 && pilihanJenisItem <= 3) {
                while (true) {
                    tampilkanDaftarItems(chestsItems[pilihanJenisItem - 1]);
                    cout << "\nMenu:\n1. Tambah Item\n2. Edit Item\n3. Hapus Item\n4. Kembali ke Menu Utama"<<endl;
                    cout << "Pilihan: ";
                    cin >> pilihanSubMenu; 
                    cin.ignore();

                    switch (pilihanSubMenu) {
                        case 1: {
                            tambahItem(chestsItems[pilihanJenisItem - 1]);
                            break;
                        }
                        case 2: {
                            editItem(chestsItems[pilihanJenisItem - 1]); 
                            break;
                        }
                        case 3: {
                            hapusItem(chestsItems[pilihanJenisItem - 1]); 
                            break;
                        }
                        case 4: {
                            break;
                        }
                        default: {
                            cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    }
                    if (pilihanSubMenu == 4) {
                        break; 
                    }
                }
            } else if (pilihanJenisItem == 4) {
                ulang = false;
                cout << "Keluar dari Program" << endl;
            } else {
                cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    } else {
        cout << "\nGagal melakukan Login!!";
    }
    return 0;
}