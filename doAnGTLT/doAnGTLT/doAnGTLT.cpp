#include<stdio.h>
#include<conio.h>
#include<string>
#include<stdlib.h>
#include<iostream>
#include<windows.h>
#include<fstream>

using namespace std;
//dinh nghia book;
struct book {
	int masach;
	char tensach[30];
	char tacgia[30];
	char nxb[30];
	int  namxb;
	char trangthai[30];
};
//dinh nghia mot node
struct bookNode {
	book infor;
	bookNode* pNext;
};
//dinh nghia mot book node
struct list {
	bookNode *pHead;
	bookNode* pTail;
};
//tao mot node moi
bookNode* taoNode(book& s) {
	bookNode* p;
	p = new bookNode;
	if (p == NULL) {
		cout << "\nkhong du bo nho";
		return NULL;
	}
	p->infor = s;p->pNext = NULL;
	return p;
}
//chen vao dau danh sach
void chenvaodau(list& l, book s) {
	bookNode* p = taoNode(s);
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
//chen vao cuoi danh sach
void chenvaocuoi(list& l, book s) {
	bookNode* p = taoNode(s);
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
//them vao sau mot node bat ki
void themvaosau(list& l, book s) {
	
}
//xoa dau danh sach
void xoadau(list& l) {
	if (l.pHead == NULL) {
		return;
	}
	bookNode* p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete p;
}

//xoa cuoi danh sach
void xoacuoi(list& l) {
	if (l.pHead == NULL) return;
	for (bookNode* k = l.pHead;k != NULL;k = k->pNext) {
		if (k->pNext == l.pTail) {
			delete l.pTail;
			k->pNext = NULL;
			l.pTail = k;
			return;
		}
	}

}
//xoa node sau node q
int xoaNodeSauq(list& l, bookNode* q) {
	if (q != NULL && q->pNext != NULL) {
		bookNode* p = q->pNext;
		q->pNext = p->pNext;
		if (p == l.pTail) l.pTail = q;
		delete p;
		return 1;
	}
	else return 0;
}

//xoa theo ten sach
int xoatensach(list& l, char kxoa[30])
{
	bookNode* p, * q = NULL;
	p = l.pHead;
	if (p == NULL)
		return 0;
	while ((p != NULL) && (strcmp(p->infor.tensach, kxoa) != 0))
	{

		q = p;
		p = p->pNext;

	}
	if (strcmp(l.pHead->infor.tensach, kxoa) == 0) 
	{
		xoadau(l);
		return 1;
	}

	if (q != NULL) 
	{
		xoaNodeSauq(l, q);
	}
	else
		return 1;

}
//xoa theo ten tac gia
int xoatentacgia(list& l, char kxoa[30])
{

	bookNode* p, * q = NULL;
	p = l.pHead;
	if (p == NULL)
		return 0;
	while ((p != NULL) && (strcmp(p->infor.tacgia, kxoa) != 0))
	{

		q = p;
		p = p->pNext;

	}
	if (strcmp(l.pHead->infor.tacgia, kxoa) == 0)
	{
		xoadau(l);
		return 1;
	}

	if (q != NULL)
	{
		xoaNodeSauq(l, q);
	}
	else
		return 1;

}
//xoa theo ma sach
int xoatheomasach(list& l, int ma)
{
	bookNode* p, * q = NULL;
	p = l.pHead;
	if (p == NULL)
		return 0;
	while ((p != NULL) && (p->infor.masach!=ma))
	{

		q = p;
		p = p->pNext;

	}
	if (l.pHead->infor.masach==ma)
	{
		xoadau(l);
		return 1;
	}

	if (q != NULL)
	{
		xoaNodeSauq(l, q);
	}
	else
		return 1;

}
//tim kiem theo ten sach
void timTenSach(list l, char ktensach[30]) {
	bookNode* R;
	R = l.pHead;
	while (R != NULL) {
		if (strcmp(R->infor.tensach, ktensach) == 0) {
			cout << "\n===========";
			cout << "\n Ma sach: " << R->infor.masach;
			cout << "\n Ten sach: " << R->infor.tensach;
			cout << "\n Ten tac gia: " << R->infor.tacgia;
			cout << "\n Nha xuat ban: " << R->infor.nxb;
			cout << "\n Nam xuat ban: " << R->infor.namxb;
			cout << "\n Trang thai: " << R->infor.trangthai;
			cout << "\n==========";
		}
		R = R->pNext;
	}
}
//tim kiem theo ten tac gia
void timtentacgia(list l, char ktacgia[30]) {
	bookNode* R;
	R = l.pHead;
	while (R != NULL) {
		if (strcmp(R->infor.tacgia, ktacgia) == 0) {
			cout << "\n===========";
			cout << "\n Ma sach: " << R->infor.masach;
			cout << "\n Ten sach: " << R->infor.tensach;
			cout << "\n Ten tac gia: " << R->infor.tacgia;
			cout << "\n Nha xuat ban: " << R->infor.nxb;
			cout << "\n Nam xuat ban: " << R->infor.namxb;
			cout << "\n Trang thai: " << R->infor.trangthai;
			cout << "\n==========";
		}
		R = R->pNext;
	}
}
//xem nhung cuon sach da cho muon(TRUE:chua muon;FALSE:da muon)
void xemSachDaMuon(list l, char ktrangthai[30]) {
	bookNode* R;
	R = l.pHead;
	while (R != NULL) {
		if (strcmp(R->infor.trangthai, ktrangthai) == 0) {
			cout << "\n===========";
			cout << "\nNhung cuon sach da cho muon";
			cout << "\nTRUE:chua muon;FALSE:da muon";
			cout << "\n Ma sach: " << R->infor.masach;
			cout << "\n Ten sach: " << R->infor.tensach;
			cout << "\n Ten tac gia: " << R->infor.tacgia;
			cout << "\n Nha xuat ban: " << R->infor.nxb;
			cout << "\n Nam xuat ban: " << R->infor.namxb;
			cout << "\n Trang thai: " << R->infor.trangthai;
			cout << "\n==========";
		}
		R = R->pNext;
	}
}
//xem nhung cuon sach chua cho muon(TRUE:chua muon;FALSE:da muon)
void xemsachchuamuon(list l, char ktrangthai[30]) {
	bookNode* R;
	R = l.pHead;
	while (R != NULL) {
		if (strcmp(R->infor.trangthai, ktrangthai) == 0) {
			cout << "\n===========";
			cout << "\nNhung cuon sach chua cho muon";
			cout << "\nTRUE:chua muon;FALSE:da muon";
			cout << "\n Ma sach: " << R->infor.masach;
			cout << "\n Ten sach: " << R->infor.tensach;
			cout << "\n Ten tac gia: " << R->infor.tacgia;
			cout << "\n Nha xuat ban: " << R->infor.nxb;
			cout << "\n Nam xuat ban: " << R->infor.namxb;
			cout << "\n Trang thai: " << R->infor.trangthai;
			cout << "\n==========";
		}
		R = R->pNext;
	}
}
//xem toan bo danh sach 
void xuat(list l) {
	int i=1;
	bookNode* R = l.pHead;
	if (R == NULL) cout << "\n Danh sach rong khong the xuat";
	else {
		while (R != NULL) {
			cout<<"\n Sach thu " << i++ << " ";
			cout<<"\n_____________";
			cout << "\nMa sach: " << R->infor.masach;
			cout << "\nTen sach: " << R->infor.tensach;
			cout << "\nTac gia: " << R->infor.tacgia;
			cout << "\nNha xuat ban: " << R->infor.nxb;
			cout << "\nNam xuat ban: " << R->infor.namxb;
			cout << "\nTrang thai: " << R->infor.trangthai;
			
			
			R = R->pNext;
			
		}
	}
}
void ghifile1book(ofstream& outfile, book s) {
	outfile << s.masach<< ",";
	outfile << s.tensach << ",";
	outfile << s.tacgia << ",";
	outfile << s.nxb << ",";
	outfile << s.namxb << ",";
	outfile << s.trangthai;
	outfile << endl;
}
void luufile(list l) {
	ofstream outfile;
	outfile.open("docfile.txt", ios::out);
	for (bookNode* k = l.pHead;k != NULL;k = k->pNext) {
		ghifile1book(outfile, k->infor);
	}
}
/*
* Đọc dữ liệu từ file "docfile.txt"
*/
void docThongTinTuFile(ifstream& filein, book& s)
{
	
	filein >> s.masach;
	filein.seekg(1, 1);
	filein >> s.tensach;
	filein.seekg(1, 1);
	filein >> s.tacgia;
	filein.seekg(1, 1);
	filein >> s.nxb;
	filein.seekg(1, 1);
	filein >> s.namxb;
	filein.seekg(1, 1);
	filein >> s.trangthai;
}
void main() {
	list l;
	l.pHead = NULL;
	l.pTail = NULL;
	book s;
	int chon, maso;
	char kxoa[30], ktimkiem[30], ktrangthai2[30] = "false", ktrangthai1[30] = "true";

	do {
		
		cout << "\n----------------";
		cout << "\n CHUONG TRINH QUAN LY THU VIEN";
		cout << "\n----------------";
		cout << "\n1.Nhap 1 quyen sach chen vao dau danh sach";
		cout << "\n2.Nhap 1 quyen sach chen vao cuoi danh sach";
		cout << "\n3.Them 1 cuon sach vao mot cuon sach nao do";
		cout << "\n4.Xoa dau danh sach";
		cout << "\n5.Xoa cuoi danh sach";
		cout << "\n6.Xoa mot cuon sach theo ten sach";
		cout << "\n7.Xoa mot cuon sach theo ten tac gia";
		cout << "\n15.Xoa mot cuon sach theo ma sach";
		cout << "\n8.Tim sach theo ten sach";
		cout << "\n9.Tim sach theo ten tac gia";
		cout << "\n10.Xem nhung cuon sach dang cho muon";
		cout << "\n14.Xem nhung cuon sach chua cho muon";
		cout << "\n11.Xem toan bo danh sach";
		cout << "\n12.Ghi file";
		cout << "\n13.Doc file";
		cout << "\n0.Exit";
		cout << "\nMoi ban chon";
		cin >> chon;
		switch (chon) {
		case 1: {
			cout << "\n\t Nhap Ma Sach: ";cin >> s.masach; 
			cout << "\n\t Nhap Ten Sach: "; cin >> s.tensach;
			cout << "\n\t Nhap Ten Tac Gia: "; cin >> s.tacgia;
			cout << "\n\t Nhap Ten NXB: "; cin >> s.nxb;
			cout << "\n\t Nhap Nam Xuat Ban: "; cin >> s.namxb;
			cout << "\n\t Trang Thai : "; cin >> s.trangthai;
		
			chenvaodau(l, s);
			break;
			}
		case 2: {
			cout << "\n\t Nhap Ma Sach: ";cin >> s.masach; 
			cout << "\n\t Nhap Ten Sach: "; cin >> s.tensach;
			cout << "\n\t Nhap Ten Tac Gia: "; cin >> s.tacgia;
			cout << "\n\t Nhap Ten NXB: "; cin >> s.nxb;
			cout << "\n\t Nhap Nam Xuat Ban: "; cin >> s.namxb;
			cout << "\n\t Trang Thai : "; cin >> s.trangthai;
			chenvaocuoi(l, s);
			break;
			}
		case 3: {
			
			}
		case 4: {
			xoadau(l);
			break;
		}
		case 5: {
			xoacuoi(l);
			break;
			}
		case 6: {
			cout << "\nnhap ten cuon sach can xoa";
			cin>>kxoa;
			xoatensach(l, kxoa);
			cout << "\nxoa thanh cong!!!";
			break;

		}
		case 7: {
			cout << "\nnhap ten tac gia cua cuon sach can xoa";
			cin >> kxoa;
			xoatentacgia(l, kxoa);
			cout << "\nxoa thanh cong!!!";
			break;

		}
		case 8: {
			cout << "\nNhap ten sach can tim:";
			cin >> ktimkiem;
			timTenSach(l, ktimkiem);
			break;

		}
		case 9: {
			cout << "\nNhap ten tac gia cua cuon sach can tim:";
			cin >> ktimkiem;
			timtentacgia(l, ktimkiem);
			break;

		}
		case 10: {
			xemSachDaMuon(l, ktrangthai2);
			break;

		}
		case 14: {
			xemsachchuamuon(l, ktrangthai1);
			break;

		}
		case 11: {
			xuat(l);
			break;
		}
		case 12: {
			luufile(l);
			ifstream infile;
			infile.open("docfile.txt",ios::out);
				infile >> s.masach;
				cout << s.masach;

				infile >> s.tensach;
				cout << s.tensach << endl;

				infile >> s.tacgia;
				cout << s.tacgia << endl;

				infile >> s.nxb;
				cout << s.nxb << endl;

				infile >> s.namxb;
				cout << s.namxb << endl;

				infile >> s.trangthai;
				cout << s.trangthai;

			infile.close();
			
			break;
		}

			   //lỗi phần đọc file
		case 13: {
			ifstream filein;
			filein.open("docfile.txt", ios::in);
			docThongTinTuFile(filein, s);
			cout << s.masach ;
			cout << s.tensach ;
			cout << s.tacgia;
			cout << s.nxb ;
			cout << s.namxb ;
			cout << s.trangthai  ;
			break;
		}
		case 15: {
			cout << "\nNhap ma sach can xoa";
			cin >> maso;
			xoatheomasach(l, maso);
			cout << "\nxoa thanh cong!!!";
			break;
		}
	}
		
	} while (chon != 0);
}