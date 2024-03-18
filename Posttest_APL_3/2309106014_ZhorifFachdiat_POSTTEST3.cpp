#include <iostream>
#include <string>
using namespace std;

//	program CRUD daftar item dalam game Risk Of Rain 2
//	Milik Zhorif Fachdiat dengan NIM 2309106014 dari kelas praktikum A1'23

string commonItems[50] = {"Armor-Piercing Rounds", "Backup Magazine", "Bison Steak", "Bundle of Fireworks", "Bustling Fungus", "Cautious Slug", "Crowbar", "Delicate Watch", "Energy Drink", "Focus Crystal", "Gasoline", "Item Scrap, White", "Lens-Maker's Glasses", "Medkit", "Mocha", "Monster Tooth", "Oddly-shaped Opal", "Paul's Goat Hoof", "Personal Shield Generator", "Power Elixir", "Repulsion Armor Plate", "Roll of Pennies", "Rusted Key", "Soldier's Syringe", "Sticky Bomb", "Stun Grenade", "Topaz Brooch", "Tougher Times", "Tri-Tip Dagger", "Warbanner"};
string uncommonItems[50] = {"AtG Missile Mk.1", "Bandolier", "Berzerker's Pauldron", "Chronobauble", "Death Mark", "Fuel Cell", "Ghor's Tome", "Harvester's Scythe", "Hopoo Feather", "Hunter's Harpoon", "Ignition Tank", "Infusion", "Item Scrap, Green", "Kjaro's Band", "Leeching Seed", "Lepton Daisy", "Old Guillotine", "Old War Stealthkit", "Predatory Instincts", "Razorwire", "Red Whip", "Regenerating Scrap", "Rose Buckler", "Runald's Band", "Shipping Request Form", "Shuriken", "Squid Polyp", "Ukulele", "War Horn", "Wax Quail", "Will-o'-the-wisp"};
string legendaryItems[50] = {"57 Leaf Clover", "Aegis", "Alien Head", "Ben's Raincoat", "Bottled Chaos", "Brainstalks", "Brilliant Behemoth", "Ceremoniak Dagger", "Defensive Microbots", "Dio's Best Friend", "Frost Relic", "H3AD-5T v2", "Happiest Mask", "Hardlight Afterburner", "Interstellar Desk Plant", "Item Scrap, Red", "Laser Scope", "N'kuhana's Opinion", "Pocket I.C.B.M","Rejuvenation Rack", "Resonance Disc", "Sentient Meat Hook", "Shattering Justice", "Soulbound Catalyst", "Spare Drone Parts", "Symbiotic Scorpion", "Unstable Tesla Coil", "Wake of Vultures"};
string bossItems[50] = {"Artifact key", "Charged Perforator", "Defense Nucleus", "Empathy Cores", "Genesis Loop", "Halcyon Seed", "Irradiant Pearl", "Item Scrap, Yellow", "Litte Discipple", "MIred Urn", "Molten Perforator", "Pearl", "Planula", "Queen's Gland", "Shatterspleen", "Titanic Knurl"};
string lunarItems[50] = {"Breads of Fealthy", "Brittle Crown", "Corpsebloom", "Defiant Gouge", "Egocentrism", "Essence of Heresy", "Eulogy Zero", "Focused Convergence", "Gesture of the Drowned", "Hooks of Heresy", "Light Flux Pauldron", "Mercurial Rachis", "Purity", "Shaped Glass", "Stone Flux Pauldron", "Strides of Heresy", "Transcendence", "Vision of Heresy", "Effigy of Grief", "Glowing Meteorite", "Hellfire Tincture", "Spinel Tonic"};
string voidItems[50] = {"Benthic Bloom", "Encrusted Key", "Lost Seer's Lenses", "Lysate Cell", "Needletick", "Newly Hatched Zoea", "Plasma Shrimp", "Pluripotent Larva", "Polylute", "Safer Spaces", "Singularity Band", "Tentabauble", "Voidsent Flame", "Weeping Fungus"};
string activeItems[50] = {"Blast Shower", "Disposable Missile Launcher", "Eccentric Vase", "Executive Card", "Foreign Fruit", "Forgive Me Please", "Fuel Array", "Gnarled Woodsprite", "Goobo Jr.", "Gorag's Opus", "Jade Elephant", "Milky Chrysalis", "Molotov", "Ocular HUD", "Preon Accumulator", "Primordial Cube", "Radar Scanner", "Recycler", "Remote Caffeinator", "Royal Capacitor", "Sawmerang", "Super Massive Leech", "The Back-up", "The Crowdfunder", "Trophy Hunter's Tricorn", "Volcanic Egg", "Her Biting Embrace", "His Reassurance", "Ifrit's Distinction", "N'kuhana's Retort", "Shared Design", "Silence Between Two Strikes", "Spectral Circlet"};

int jmlCommon=30;
int jmlUncommon=31;
int jmlLegendary=28;
int jmlBoss=16;
int jmlLunar=22;
int jmlVoid=14;
int jmlActive=33;

int gagalLogin=0;
string pilihan,namaUser,nimUser;
bool ulang=true,login;

int tambahItems(int jumlah,string items[]){
	cout<<"\nTambah Item\nItem baru : ";
	cin.ignore();
	getline(cin,items[jumlah]);
	cout<<"\nItem telah tertambah\n"<<endl;
	return jumlah+=1;
}

void editItems(int jumlah,string items[]){
	cout<<"\nEdit Item\nPilhan Urutan : ";
	int pilihan;
	cin.ignore();
	cin>>pilihan;
	if(pilihan>0 && pilihan<=jumlah){
		cout<<items[pilihan-1]<<"\nUbah menjadi : ";
		cin.ignore();
		getline(cin,items[pilihan-1]);
		cout<<"\nItem telah terubah\n"<<endl;
	}else{
		cout<<"\nUrutan tidak terdaftar\n"<<endl;
	}
}

int hapusItems(int jumlah,string items[]){
	cout<<"\nHapus Item\nPilhan Urutan : ";
	int urutan;
	cin>>urutan;
	if(urutan>0 && urutan<=jumlah){
		for(int i=urutan-1;i<jumlah-1;i++){
			items[i]= items[i+1];
		}
		cout<<"\nItem telah terhapus\n"<<endl;
		jumlah-=1;
	}else{
		cout<<"\nUrutan tidak terdaftar\n"<<endl;
	}
	return jumlah;
}

void outputlist(int jumlah,string items[]){
	for(int i=0;i<jumlah;i++){
		cout<<i+1<<". "<<items[i]<<endl;
	}
}

int menuSekunder(int jumlah,string items[],string jenis){
	bool ulangsekunder=true;
	string pilihan;
	while(ulangsekunder==true){
	cout<<"\nDaftar "<<jenis<<endl;
		outputlist(jumlah,items);
		cout<<"\nMenu Sekunder\n1. Tambah Item\n2. Edit Item\n3. Hapus Item\n4. Back\nPilihan : ";
		cin>>pilihan;
		if(pilihan=="1"){
			jumlah=tambahItems(jumlah,items);
		}else if(pilihan=="2"){
			editItems(jumlah,items);
		}else if(pilihan=="3"){
			jumlah=hapusItems(jumlah,items);
		}else if(pilihan=="4"){
			cout<<"\nKembali Ke Menu Utama\n";
			ulangsekunder=false;
		}else{
			cout<<"\nPilihan tidak ditemukan!!\n"<<endl;
		}
	}
	return jumlah;
}

bool menuUtama(bool ulang){
	if(ulang==false){
		return ulang=false;
	}else{
		cout<<"\nMenu Utama\n1. Common Items\n2. Uncommon Items\n3. Legendary Items\n4. Boss Items\n5. Lunar Items\n6. Void Items\n7. Active Items\n8. Exit Program\n";	
		cout<<"Pilihan : ";
		cin>>pilihan;  
		if(pilihan=="1"){
			jmlCommon=menuSekunder(jmlCommon,commonItems,"Common Items");
		}else if(pilihan=="2"){
			jmlUncommon=menuSekunder(jmlUncommon,uncommonItems,"Uncommon Items");
		}else if(pilihan=="3"){
			jmlLegendary=menuSekunder(jmlLegendary,legendaryItems,"Legendary Items");
		}else if(pilihan=="4"){
			jmlBoss=menuSekunder(jmlBoss,bossItems,"Boss Items");
		}else if(pilihan=="5"){
			jmlLunar=menuSekunder(jmlLunar,lunarItems,"Lunar Items");
		}else if(pilihan=="6"){
			jmlVoid=menuSekunder(jmlVoid,voidItems,"Void Items");
		}else if(pilihan=="7"){
			jmlActive=menuSekunder(jmlActive,activeItems,"Active Items");
		}else if(pilihan=="8"){
			cout<<"\nKeluar Program";
			ulang=false;
		}else {
			cout<<"\nPilihan tidak ditemukan!!\n";
		}
		return menuUtama(ulang);
    }
} 

int main(){
	cout<<"Selamat datang di program Daftar item dalam game Risk Of Rain 2\nSilahkan melakukan login terlebih dahulu\n"<<endl;
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
			ulang=menuUtama(ulang);
		}
	}else{
		cout<<"\nGagal melakukan Login!!";
	}
	cin.get();
	return 0;
}