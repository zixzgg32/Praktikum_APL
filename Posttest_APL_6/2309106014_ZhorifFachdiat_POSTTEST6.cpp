#include <iostream>
#include <string>
#include <limits>
#include <windows.h>
using namespace std;

//	program CRUD daftar item dalam game Risk Of Rain 2
//	Milik Zhorif Fachdiat dengan NIM 2309106014 dari kelas praktikum A1'23

int gagalLogin=0,pilihanJenisItem,pilihanSubMenu,pilihanSorting;
string namaUser,nimUser,cari;
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
			cout << "\nInputan nama ataupun NIM salah\n" << endl;
			gagalLogin++;
		}	
	}
	return berhasilLogin;
}

struct items{
	string nama;
	string stack;
	string unlocked;
	float perstack;
};
struct itemROR2{
	string rarityItems;
	int jumlahItems;
	items dataItems[50];
};

itemROR2 chestsItems[3]= {
	{"Common Items",29,{{"Armor-Piercing Rounds","Linear","Advancement", 20}, {"Backup Magazine","Linear","Flawless", 1}, {"Bison Steak","Linear","Default", 25}, {"Bundle of Fireworks","Linear","...Maybe One More", 25}, {"Bustling Fungus","Linear","Default", 2.25}, {"Cautious Slug","Linear","Default", 3}, {"Crowbar","Linear","The Basics", 75}, {"DelicLinearate Watch","Linear","Survivors of the Void", 20}, {"Energy Drink","Linear","Default", 25}, {"Focus Crystal","Linear","Default", 20}, {"Gasoline","Linear","Default", 4}, {"Lens-Maker's Glasses","Linear","Default", 10}, {"Medkit","Linear","Default", 5}, {"Mocha","Linear","Survivors of the Void", 7.5}, {"Monster Tooth","Linear","Default", 2}, {"Oddly-shaped Opal","Linear","Survivors of the Void", 100}, {"Paul's Goat Hoof","Linear","Is This Bugged?", 14}, {"Personal Shield Generator","Linear","Default", 8}, {"Power Elixir","-","Survivors of the Void", 1}, {"Repulsion Armor Plate","Linear","Default", 5}, {"Roll of Pennies","Linear","Survivors of the Void", 3}, {"Rusted Key","-","Keyed Up", 1}, {"Soldier's Syringe","Linear","Default", 15}, {"Sticky Bomb","Linear","Default", 5}, {"Stun Grenade","Hyperbolic","Default", 5}, {"Topaz Brooch","Linear","Default", 15}, {"Tougher Times","Linear","Default", 15}, {"Tri-Tip Dagger","Linear","Default", 10}, {"Warbanner","Linear","Default", 8}}},
	{"Uncommon Items",30,{{"AtG Missile Mk.1","Linear","Default", 300}, {"Bandolier","Special","Default", 10}, {"Berzerker's Pauldron","Linear","Glorious Battle", 4}, {"Chronobauble","Linear","Default", 2}, {"Death Mark","Linear","Default", 7}, {"Fuel Cell","Linear Exponential","Experimenting", 1}, {"Ghor's Tome","Linear","Default", 4}, {"Harvester's Scythe","Linear","Prismatically Aligned", 4}, {"Hopoo Feather","Linear","Default", 1}, {"Hunter's Harpoon","Linear","Survivors of the Void", 0.5}, {"Ignition Tank","Linear","Survivors of the Void", 300}, {"Infusion","Linear","Slaughter", 100}, {"Kjaro's Band","Linear","Death Do Us Part", 300}, {"Leeching Seed","Linear","Default", 1}, {"Lepton Daisy","Linear","Default", 1}, {"Old Guillotine","Hyperbolic","Cut Down", 13}, {"Old War Stealthkit","Exponential","Default", 50}, {"Predatory Instincts","None Linear","Rapidfire", 24}, {"Razorwire","Linear","Default", 2}, {"Red Whip","Linear","Default", 30}, {"Regenerating Scrap","-","Survivors of the Void", 1}, {"Rose Buckler","Linear","Default", 30}, {"Runald's Band","Linear","Death Do Us Part", 250}, {"Shipping Request Form","Special","Survivors of the Void", 1}, {"Shuriken","Linear","Survivors of the Void", 100}, {"Squid Polyp","Linear","Automation Activation", 100}, {"Ukulele","Linear","Default", 2}, {"War Horn","Linear","Warmonger", 4}, {"Wax Quail","Linear","Going Fast Recommended", 10}, {"Will-o'-the-wisp","Linear","Default", 280}}},
	{"Legendary Items",27,{{"57 Leaf Clover","Linear","The Long Road", 1}, {"Aegis","Linear","Default", 50}, {"Alien Head","Exponential","Default", 25}, {"Ben's Raincoat","None Linear","Survivors of the Void", 1}, {"Bottled Chaos","Linear","Survivors of the Void", 1}, {"Brainstalks","Linear","Deicide", 4}, {"Brilliant Behemoth","Linear","Default", 2.5}, {"Ceremoniak Dagger","Linear","Default", 150}, {"Defensive Microbots","Linear","Default", 1}, {"Dio's Best Friend","Linear","The Lone Survivor", 1}, {"Frost Relic","Linear","Default", 12}, {"H3AD-5T v2","Reciprocal","Default", 50}, {"Happiest Mask","Linear","Default", 30}, {"Hardlight Afterburner","Linear","Default", 2}, {"Interstellar Desk Plant","Linear","Default", 5}, {"Laser Scope","Linear","Survivors of the Void", 100}, {"N'kuhana's Opinion","Linear","Her Concepts", 100}, {"Pocket I.C.B.M","None Linear","Survivors of the Void", 50}, {"Rejuvenation Rack","Linear","Naturopath", 100}, {"Resonance Disc","Linear","Default", 300}, {"Sentient Meat Hook","Linear","Deja Vu?", 20}, {"Shattering Justice","Linear","Default", 8}, {"Soulbound Catalyst","Linear","Newtist", 2}, {"Spare Drone Parts","Linear","Survivors of the Void", 50}, {"Symbiotic Scorpion","Linear","Survivors of the Void", 2}, {"Unstable Tesla Coil","Linear","Macho", 2}, {"Wake of Vultures","Linear","Default", 5}}}
};

void tampilkanDataItem(items *item) {
    cout << item->nama << " (+" << item->perstack << " perstack)" << endl;
    cout << "    Stack type : " << item->stack << endl;
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
    
    cout << "Masukkan Jumlah Item Perstack : ";
    cin >> chest.dataItems[chest.jumlahItems].perstack;
	
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
	        cout << "4. Edit Perstack (sekarang: " << item.perstack << ")" << endl;
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
		            case 4: {
		            	cout << "Masukkan Perstack Baru: ";
		            	cin >> item.perstack;
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

// Selection Sort Nama (string) secara Descendinng
void sortingNamaDescending(itemROR2 &chest) {
    for (int i = 0; i < chest.jumlahItems - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < chest.jumlahItems; j++) {
            if (chest.dataItems[j].nama > chest.dataItems[min_idx].nama) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(chest.dataItems[i], chest.dataItems[min_idx]);
        }
    }
}

// Selection Sort Nama (string) secara Ascending
void sortingNamaAscending(itemROR2 &chest) {
    for (int i = 0; i < chest.jumlahItems - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < chest.jumlahItems; j++) {
            if (chest.dataItems[j].nama < chest.dataItems[min_idx].nama) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(chest.dataItems[i], chest.dataItems[min_idx]);
        }
    }
}


// Bubble Sort Stack secara Ascending
void sortingStack(itemROR2 &chest) {
    for (int i = 0; i < chest.jumlahItems - 1; i++) {
        for (int j = 0; j < chest.jumlahItems - i - 1; j++) {
            if (chest.dataItems[j].stack > chest.dataItems[j + 1].stack) {
                swap(chest.dataItems[j], chest.dataItems[j + 1]);
            }
        }
    }
}

// Insertion Sort Perstack (angka) secara Ascending)
void sortingPerstack(itemROR2 &chest) {
    for (int i = 1; i < chest.jumlahItems; i++) {
        items key = chest.dataItems[i];
        int j = i - 1;
        while (j >= 0 && chest.dataItems[j].perstack > key.perstack) {
            chest.dataItems[j+1] = chest.dataItems[j];
            j = j - 1;
        }
        chest.dataItems[j+1] = key;
    }
}

// Binary Search Nama dari data Ascending
int binarySearch(itemROR2 &chest, string namaItem) {
	sortingNamaAscending(chest);
    int left = 0;
    int right = chest.jumlahItems - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (chest.dataItems[mid].nama == namaItem) {
            return mid; 
        } else if (chest.dataItems[mid].nama < namaItem) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
    return -1; 
}

// Sequential Search Nama dari data Descending
int sequentialSearch(itemROR2 &chest, string namaItem) {
	sortingNamaDescending(chest);
    for (int i = chest.jumlahItems - 1; i >= 0; i--) {
        if (chest.dataItems[i].nama == namaItem) {
            return i; 
        }
    }
    return -1; 
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
                    cout << "\nMenu:\n1. Tambah Item\n2. Edit Item\n3. Hapus Item\n4. Sorting Items\n5. Search Item\n6. Kembali" << endl;
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
                        	cout << "\nSorting secara :\n1. Nama Item\n2. Jenis Stack\n3. Stack Items" << endl;
                        	cout << "Pilihan: ";
                        	cin >> pilihanSorting;
                        	cin.ignore();
                        	
                        	switch (pilihanSorting) {
                        		case 1: {
                        			sortingNamaDescending(chestsItems[pilihanJenisItem - 1]);
									break;
								}
								case 2: {
									sortingStack(chestsItems[pilihanJenisItem - 1]);
									break;
								}
								case 3: {
									sortingPerstack(chestsItems[pilihanJenisItem - 1]);
									break;
								}
								default: {
									cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
		                            cin.clear();
		                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
								}
							}
							break;
                        }
                        case 5: {
                        	cout << "\nMasukkan nama item yang ingin dicari: ";
						    getline(cin, cari);
						    cout << "\nSearch Item secara :\n1. Data Ascending Binary Search\n2. Data Descending Sequential Search\n" << endl;
						    cout << "Pilihan: ";
						    cin >> pilihanSorting;
						    cin.ignore();
						    switch (pilihanSorting) {
						        case 1: {
						            int index = binarySearch(chestsItems[pilihanJenisItem - 1], cari);
						            if (index != -1) {
						                cout << "\nItem ditemukan pada indeks " << index + 1 << " dari daftar Common Items." << endl;
						                cout << "Detail Item:\n";
						                tampilkanDataItem(&chestsItems[pilihanJenisItem - 1].dataItems[index]);
						                cout << "Tekan Enter Untuk Melanjutkan" << endl;
						        		cin.get();
						            } else {
						                cout << "\nItem tidak ditemukan." << endl;
						            }
						            break;
						        }
						        case 2: {
						            int index = sequentialSearch(chestsItems[pilihanJenisItem - 1], cari);
						            if (index != -1) {
						                cout << "\nItem ditemukan pada indeks " << index + 1 << " dari daftar Common Items." << endl;
						                cout << "Detail Item:\n";
						                tampilkanDataItem(&chestsItems[pilihanJenisItem - 1].dataItems[index]);
						                cout << "Tekan Enter Untuk Melanjutkan" << endl;
						     		    cin.get();
						            } else {
						                cout << "\nItem tidak ditemukan." << endl;
						            }
						            break;
						        }
						        default: {
						            cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
						            cin.clear();
						            cin.ignore(numeric_limits<streamsize>::max(), '\n');
						        }
						    }
						}
						case 6: {
							break;
						}
                        default: {
                            cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    }
                    if (pilihanSubMenu == 6) {
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