#include<iostream>
#include <windows.h>
#include <malloc.h>
#include <bits/stdc++.h>
#define max 100
#define True 1
#define False 0               //KURANG STACK, FILE
using namespace std;

typedef string kata; //membuat kata menjadi sama dengan string
typedef int typeinfo; // membuat typeinfo samadengan int
typedef float jml; // membuat jml samadengan float
typedef struct typenode *typeptr; //untuk mendefinisikan node
struct typenode{ //sebuah record yang digunakan untuk menyimpan data node, typenode akan masuk ke typeinfo info dan typeptr next
	typeinfo info; //int
	typeptr next; //penunjuk
};

typeptr awal, akhir; //typeptr merupakan deklarasi awal dan akhir. awal dan akhir merupakan penunjuk bagaimana nanti awal dan akhirnya pointer
void buatlistbaru(); // deklarasi function supaya bisa membuat list baru
void sisipdepan(typeinfo IB); // deklarasi fungsi sisipdepan dengan parameter IB
void hapus();
void hapuslist(typeinfo IH); //deklarasi fungsi hapuslist dengan parameter IH
void cetaklist(); //deklarasi fungsi untuk output data
void keluar(); //deklarasi keluar program
void transaksi();
void kirim();
void garis();
char back;
int pilih, byk, pilihan;

struct coba{ //mendefinisikan strust typequeue yang berisi int belakang dan elemen[max] dgn max =12
	int belakang;
	int elemen[max];
};
coba que;
int jmlstok, carik;
bool cek;
void menu();
void cari(int crkode);
void buatqueue(); //mendefinisikan fungsi buatqueue dgn inisialisasi queue.belakang = 0
void cetakqueue(); // fungsi cetak daftar transaksi
void enqueue(int IB); // fungsi enqueue dgn parameter IB untuk menyisipkan antrian
void dequeue(); //fungsi dequeque untuk menghapus data pada saat membatalkan kiriman
int queuekosong(); //fungsi queuekosong untuk mengecek apakah antrian kosong
int queuepenuh(); // fungsi queuepenuh untuk mengecek apakah antrian penuh

struct data{ // membuat struct bernama data
	typeinfo kode, stok, harga, pesanan, total;
	typeinfo jmlpesanan, ttlpesanan, banyak; //typeinfo = int
	char nama[20];
	char namapembeli[20], alamat[20];
};
data ada[200]; //max value of array 200
typeinfo angka=1, no=1; // int dengan nama variabel angka yang bervalue 0
int main(){
	buatlistbaru(); //panggil fungsi buatlistbaru
	buatqueue(); //memanggil fungsi buat queue
	menu();
}
void menu(){
	do{
		system("cls");
		cout<<"=================================================\n";
		cout<<"|  PROYEK PRAKTIKUM IMPLEMENTASI STRUKTUR DATA  |\n";
		cout<<"|                                               |\n";
		cout<<"|NIM    : - 123200001                           |\n";
		cout<<"|         - 123200013                           |\n";
		cout<<"|                                               |\n";
		cout<<"|Kelas  : IF-G                                  |\n";
		cout<<"=================================================\n\n";
		cout<<"\tKasir SUPERMARKET 'Sumber Rezeki' \n\n";
		cout<<"===================================\n";
		cout<<"|                                 |\n";
		cout<<"|   1. Input Data Barang          |\n";
		cout<<"|   2. Lihat Data Barang          |\n";
		cout<<"|   3. Hapus Data Barang          |\n";
		cout<<"|   4. Cari Data Barang dgn Kode  |\n";
		cout<<"|   5. Transaksi                  |\n";
		cout<<"|   6. Keluar                     |\n";
		cout<<"|                                 |\n";
		cout<<"===================================\n\n";
		cout<<"   Pilihan = ";
		cin>>pilih;
		cout<<"\n\n";
		switch(pilih){
			case 1 :
				system("cls");
				cout<<"=====================================\n";
				cout<<"|         INPUT DATA BARANG         |\n";
				cout<<"=====================================\n\n";
				cout<<"Masukkan banyak data : "; cin>>byk;
				cout<<"\n";
				for(int i=1; i <= byk; i++){
					cout<<"Data ke-"<<angka<<endl;
					ada[angka].kode = angka;
					cout<<" - Kode Barang  : "<<ada[angka].kode<<endl;
					cout<<" - Nama Barang  : "; cin.ignore(); cin.getline(ada[angka].nama,20);// input dengan menggunakan angka sebagai index agar bisa disimpan
					cout<<" - Harga Barang : "; cin>>ada[angka].harga;
					cout<<" - Stok         : "; cin>>ada[angka].stok;
					cout<<"\n";
					sisipdepan(angka); // panggil fungsi sisipdepan dengan parameter angka
					angka++;
				}
				break;
			case 2 :
				system("cls");
				cout<<"======================================\n";
				cout<<"|             LIHAT DATA             |\n";
				cout<<"======================================\n\n";
				cetaklist(); // panggil fungsi cetaklist lalu akan menampilkan data
				break;
			case 3 :
				cout<<"======================================\n";
				cout<<"|             HAPUS DATA             |\n";
				cout<<"======================================\n\n";
				cetaklist();
				cout<<"\n==> Masukkan Kode Barang yg akan dihapus : ";
				cin>>angka;
				hapuslist(angka); // panggil fungsi hapuslist
				break;
			case 4 :
				cout<<"=====================================\n";
				cout<<"|             CARI DATA             |\n";
				cout<<"=====================================\n\n";
				cout<<"\n==> Masukkan Kode Barang yg dicari : ";
				cin>>carik;
				cout<<"\n";
				cari(carik); // panggil fungsi cari
				break;
			case 5 :
				transaksi();
				break;
			case 6 :
				keluar();
				break;
			default:
				cout<<"Tidak Ada Pilihan Lain!\nSilahkan Ulangi Kembali!!\n\n";
				system("pause");
				main();
		}
		cout<<"\n==> Kembali Ke Menu Utama(y/n) ? = ";
		cin>>back;
	}while(back == 'y' || back == 'Y');
	keluar();	
}
void cari (int crkode){
	typeptr bantu; //penunjuk bantu
	bantu=awal; // bantu menunjuk awal
	while(bantu != NULL){
		if(crkode == ada[bantu->info].kode){
			cout<<"Kode Barang   = "<<bantu->info<<endl;
			cout<<"Nama Barang   = "<<ada[bantu->info].nama<<endl;
			cout<<"Harga Barang  = "<<ada[bantu->info].harga<<endl;
			cout<<"Stok          = "<<ada[bantu->info].stok<<endl<<endl;
		}
		bantu=bantu->next;
	}
}
void buatlistbaru()
{
	typeptr list; //typeptr yang menunjuk pada sebuah pointer, typeptr list itu mendekarasikan list yang bertipe pointer
	list=(typenode*)malloc(sizeof(typenode)); //membuat tempat kosong untuk list
	list=NULL; //list menunjuk ke tempat kosong
	awal=list; // awal menunjuk list
	akhir=list; //akhir menunjuk list
}

void sisipdepan(typeinfo IB){
	typeptr NB; //mendeklarasikan sebuah node baru
	NB=(typenode*)malloc(sizeof(typenode)); //node baru yang kosong atau belum terdapat nilai
	NB->info=IB; //node mulai terisi, yang didapat dari parameter typeinfo IB
	if(awal==NULL) //untuk mengecek apakah linked list masih kosong atau tidak, jika 
					//kosong maka dia akan menunjuk pada node baru yaitu jalan ke awal=NB dan akhir=NB
	{
		awal=NB; //awal menunjuk NB
		akhir=NB; //akhir menunjuk NB
		awal->next=NULL; //awal next/awal yg selanjutnya menunjuk NULL/KOSONG
	}
	else
	{
		NB->next=awal; //NB next/NB selanjutnya menunjuk ke awal
	}
	awal=NB; // awal samadengan NB
}
void garis(){
	for (int i = 0; i < 75; i++)
	{
		cout << "=";
	}
	cout << endl;
}

void cetaklist(){ 
	typeptr bantu; //penunjuk bantu
	bantu=awal; // bantu menunjuk awal
	garis();
	cout<<left<<setw(20)<<"  Kode Barang"<<setw(20)<<"Nama Barang"<<setw(20)<<"Harga Barang"<<setw(20)<<"Stok"<< endl;
	garis();
	while (bantu!=NULL) //perulangan jika bantu tidak kosong / data sudah ada
	{	
		cout<<"  "<<left<<setw(18)<<ada[bantu->info].kode<<setw(20)<<ada[bantu->info].nama<<setw(20)<<ada[bantu->info].harga<<setw(20)<<ada[bantu->info].stok<<endl;
		bantu=bantu->next;
	}
	garis();
}
void hapuslist(typeinfo IH){
	typeptr hapus, bantu; //mendeklarasikan variabel hapus dan bantu
	if (awal==NULL) //percabangan, dimana jika awal list kosong maka akan menampilkan informasi bahwa list masih kosong
	{ printf("List masih kosong!\n"); }
	
	else
	{
		if (awal->info==IH) { //percabangan, dimana awal list yang berisi dan akan dihapus, maka akan terjadi penghapusan di awal list
			hapus=awal;
			awal=hapus->next; //kemudian posisi awal list yg dihapus akan berpindah ke node selanjutnya sebagai awal list
			free(hapus);
		}
		else { 
			bantu=awal; //variabel bantu sama dengan atau berada diposisi node awal untuk mencari list yang akan dihapus
			while ((bantu->next->info!=IH) && (bantu->next!=NULL)) //terjadi perulangan, 
				{ bantu=bantu->next; } 
			hapus=bantu->next; 
			if (hapus==NULL) { //jika hapus sama dengan atau dalam kondisi kosong, maka akan muncul tampilan list tidak ditemukan
				cout<<"List tidak ditemukan!";	}
			else{ 
				if (hapus==akhir){ //untuk menghapus akhir list
					akhir=bantu; //akhir list sama dengan variabel bantu
					akhir->next=NULL;
				} //kemudian akhir list akan berpindah ke list selanjutnya yang kosong
			 	else { //untuk menghapus tengah list
				 	bantu->next=hapus->next; 
				}	//terjadi variabel bantu pindah ke list selanjutnya sampai berada di list yang akan dihapus
				free(hapus); 
			}
		}
	}
}

void transaksi(){
	do{
		system("cls");
		cout<<"====================================\n";
		cout<<"|            TRANSAKSI             |\n";
		cout<<"====================================\n\n";
		cout<<"====================================\n";
		cout<<"|                                  |\n";
		cout<<"| [1]. Input Data Pesanan          |\n";
		cout<<"| [2]. Lihat Data Pesanan          |\n";
		cout<<"| [3]. Batalkan Pesanan            |\n";
		cout<<"| [4]. Kirim Pesanan Pembeli       |\n";
		cout<<"| [5]. Kembali                     |\n";
		cout<<"|                                  |\n";
		cout<<"====================================\n";
		cout<<" Masukkan Pilihan = "; cin>>pilihan;
		cout<<"\n";
		if(pilihan == 1){
			cout<<"======================================\n";
			cout<<"|         INPUT DATA PESANAN         |\n";
			cout<<"======================================\n\n";
			cout<<"Masukkan banyak data antrian : "; cin>>byk;
			cout<<"\n";
			for(int i = 1; i <= byk; i++){
				cout<<"Pembeli "<<no<<endl;
				cout<<" - Nama Pelanggan : "; cin.ignore(); cin.getline(ada[no].namapembeli, 20);
				cout<<" - Alamat         : "; cin.getline(ada[no].alamat, 20);
				cout<<" - Banyak barang yang dipesan : "; cin>>ada[no].banyak;
				for(int j=1; j<=ada[no].banyak; j++){
					cek = false;
					cout<<"    "<<j<<". Kode Barang    : "; cin>>ada[j].pesanan;
					for(int k = 1; k <= angka-1; k++){
						if(ada[j].pesanan == ada[k].kode){
							cek = true;
							cout<<"       Nama Barang    : "<<ada[k].nama<<"\n";
							cout<<"       Jumlah Pesanan : "; cin>>ada[k].jmlpesanan;
							if(ada[k].stok >= ada[k].jmlpesanan){
								ada[k].ttlpesanan = ada[k].jmlpesanan * ada[k].harga;
								cout<<"       Total bayar    : "<<ada[k].ttlpesanan<<endl;
								ada[k].stok = ada[k].stok - ada[k].jmlpesanan;
								ada[no].total = ada[no].total + ada[k].ttlpesanan;
							}
							else{
								cout<<"\n    Maaf stok perhiasan tidak cukup!!!\n\n\n";
								system("pause");
								transaksi();
							}
						}
					}
				}
				if(cek == true){
					cout<<" - Total seluruh : "<<ada[no].total<<endl;
					cout<<"\n";
					enqueue(no);//memangil fungsi enqueue dengan parameter int i
					no++;
				}
			}
		}
		else if(pilihan == 2){
			cout<<"================================\n";
			cout<<"|         DATA PESANAN         |\n";
			cout<<"================================\n\n";
			cetakqueue();//panggil fungsi cetakqueue untuk menyetak daftar pesanan
		}
		else if(pilihan == 3){
			cout<<"====================================\n";
			cout<<"|         BATALKAN PESANAN         |\n";
			cout<<"====================================\n\n";
			dequeue(); //panggil fungsi dequeue untuk menahpus pesanan yg dibatalkan
		}
		else if(pilihan == 4){
			kirim(); // pangil fungsi kirim untuk mengirim pesanan
		}
		else if(pilihan == 5){
			menu(); // pangil fungsi menu untuk kembali ke menu
		}
		else{//jika pilihan < 0 dan > 5
			cout<<"\nPilihan Anda Tidak Ada!!\nSilahkan Ulangi Kembali!\n\n";
			system("pause");
			transaksi();//kembali ke fungsi transaksi
		}
		cout<<"\n--> Kembali ke Menu Transaksi(y/n)? = "; cin>>back;//input back untuk mengulang atau exit
	}while(back == 'y' || back == 'Y');
}

void buatqueue(){ 
 	que.belakang = 0; //inisialisasi queue.belakang = 0
}

int queuekosong(){ 
 	if(que.belakang==0) //jika queue belakang null maka return true, jika tidak retur false
		return(True);
 	else
		return(False); 
}

int queuepenuh(){
	if(que.belakang==max)//jika queue.belakan = 15 maka return true jika tidak return false
		return(True);
 	else
		return(False); 
}
void enqueue(int IB){//input
	if(queuepenuh())//cek apakah queue penuh
		cout << "queue overflow\n";
 	else{
	 	que.belakang++;//queue.belakang menjadi queue.belakang + 1
 		que.elemen[que.belakang]=IB; //queue.elemen[queue.belakang] samadengan IB 
	}
}

void cetakqueue(){
	if(que.belakang != 0){ //cek jika queue.belakang tidak 0 atau ada isinya
		int i=1;//inisialisasi i =1
		while(i<=que.belakang){ //perulangan while jika i <= queue.belakang
			cout<<"Pelanggan ke-"<<que.elemen[i]<<"\n"; //output queue.elemen[i]
			cout<<"     Nama Pelanggan  = "<<ada[que.elemen[i]].namapembeli<<"\n"; // output data nama dengan index queue.elemen[i]
			cout<<"     Alamat          = "<<ada[que.elemen[i]].alamat<<"\n"; 
			cout<<"     Total seluruh   = "<<ada[que.elemen[i]].total<<endl;
			cout<<"\n";
			i++; //i = i + 1
		}
	}
	else{//jika dftar kosong/queue.belakang=0
		cout<<"Belum Ada Daftar Pesanan!!\n";
	}
}

void dequeue(){//hapus
	int ID, i;
 	if(queuekosong()) //cek apakah queue kosong
		cout << "Belum Ada Daftar Transaksi!!\n";
 	else{
	 	ID=que.elemen[1]; // mengisi ID dari queue.elemen[1]
	 	cout<<"Pemesanan atas nama "<<ada[ID].namapembeli<<" berhasil dibatalkan\nTerima Kasih!\n";//output data nama yg dibatalkan
	 	if(ada[ID].banyak > 1){
	 		for(int j=1; j <= ada[ID].banyak; j++){
	 			ada[j].stok = ada[j].stok + ada[j].jmlpesanan;	
			}
			ada[ID].total=0;
		}
		else if(ada[ID].banyak == 1){
			ada[ID].stok = ada[ID].stok + ada[ID].jmlpesanan; //menambah stok dengan ada[ID].jmlpesanan karena pesanan dibatalkan
			ada[ID].total=0;
		}
 		for (i=1; i<que.belakang; i++){ //perulangan for diawali i=1 dengan batas i<queuebelakang dan i++
 			que.elemen[i]=que.elemen[i+1]; // mengisi queue.elemen[i] menjadi queue.elemen[i+1]
			 
		}
 		que.belakang--; // queue.belakang menjadi queue.belakang-1
	}
}
void kirim(){
	if(que.belakang != 0){//cek jika queue.belakang tidak 0
		int j = 1;//inisialisasi j=1
		cout<<"Pesanan dengan data berikut berhasil dikirimkan : \n";
		cout<<"   - Nama   = "<<ada[que.elemen[j]].namapembeli<<"\n"; //output data nama dgn index queue.elemen[j]
		cout<<"     Alamat = "<<ada[que.elemen[j]].alamat<<"\n"; //output data alamat dgn index queue.elemen[j]
		cout<<"     Total  = "<<ada[que.elemen[j]].total<<"\n\n"; //output data alamat dgn index queue.elemen[j]
		hapus(); // panggil fungsi hapus antrian karena pesanan berhasil dikirimkan
		if(que.belakang != 0){ // cek apakah daftar transaksi tidak kosong
			cout<<"Pesanan dengan data berikut belum dikirim : \n";
			j=1; // inisialisasi j = 1
			while(j<=que.belakang){//perulangan while jika i <= queue.belakang
				cout<<"   - Nama   = "<<ada[que.elemen[j]].namapembeli<<"\n"; //output data nama dgn index queue.elemen[j]
				cout<<"     Alamat = "<<ada[que.elemen[j]].alamat<<"\n"; //output data alamat dgn index queue.elemen[j]
				cout<<"     Total  = "<<ada[que.elemen[j]].total<<"\n\n"; //output data alamat dgn index queue.elemen[j]
				j++; // j = j + 1
			}
		}
		else{//jika daftar transaksi kosong
			cout<<"Semua Data Sudah Berhasil Dikirimkan\n";
		}
	}
	else{//jika daftar transaksi kosong
		cout<<"Belum Ada Daftar Transaksi!!\n";
	}
}
void hapus(){//hapus stelah kirim pesanan
	int ID, i;
	ID=que.elemen[1]; //mengisi ID dari queue.elemen[1]
 	for (i=1; i<que.belakang; i++){//prulangan for diawali i =1, batas i<queue.belakang dan i++
 		que.elemen[i]=que.elemen[i+1]; // mengisi queue.elemen[i] menjadi queue.elemen[i+1] 
	}
 	que.belakang--;// queue.belakang menjadi queue.belakang-1
}

void keluar(){
	system("cls");
	cout<<"\n\n\n\t\tTerimakasih Atas Kunjuangan Anda ^_^\n\t\tSampai Jumpa untuk berbelanja kembali !!!\n";
	cout<<"\t";
	for(int i = 0; i < 17; i++){
		cout<<" . "; Sleep(200); //perulangan untuk membuat loading dengan waktu 200ms
	}
	cout<<"\n\n\n";
	exit(0);
}
