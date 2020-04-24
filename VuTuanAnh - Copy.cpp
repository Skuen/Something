//MSSV: N18DCCN010
#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include <fstream>
using namespace std;

struct sinhvien{
	int mssv;
	char ho[40];
	char ten[10];
};

//===============DSLK===================
struct nodesv{
	sinhvien sv;   //info
	nodesv* next;  //nút
};

typedef nodesv * PTR;

struct linked_list{
	PTR first;
	PTR last;
};

void Khoi_tao(linked_list &L)
{
	L.first = L.last = NULL;
}

PTR newnode(sinhvien x)
{
	PTR p = new nodesv;
	p->sv=x;
	p->next=NULL;
	return p;
}

void insert_first(linked_list &L, PTR p)
{
	if(L.first==NULL)
	{
		L.first=L.last=p;
	}
	else
	{
		p->next=L.first;
		L.first=p;
	}
}
void insert_last(linked_list &L, PTR p)
{
	if(L.first==NULL)
	{
		L.first=L.last=p;
	}
	else
	{
		L.last->next=p;
		L.last = p;
	}
}

//=============Con lai===========
void NhapChuoi (char *tieude, char *S) {
	cout << tieude ;  fflush(stdin);
    do
	  gets(S);
    while (strcmp(S,"")==0)  ;	
}

void sort_ms(linked_list &liz)
{
	if(liz.first==NULL)
	{
		cout<<"Khong co sinh vien nao trong danh sach"<<endl;
		cout<<"\nNhan Enter de tro lai menu"<<endl;
		system("pause");
		return;
	}
	for(PTR p=liz.first;p!=NULL;p=p->next)
	{
		for(PTR k=p->next;k!=NULL;k=k->next)
		{
			if(p->sv.mssv>k->sv.mssv)
			{
				swap(p->sv,k->sv);
			}
		}
	}
}

void sort_name(linked_list &L)
{
	for(PTR p=L.first;p!=NULL;p=p->next)
	{
		for(PTR k=p->next;k!=NULL;k=k->next)
		{
			if(p->sv.ten[0]==k->sv.ten[0])
			{
				if(p->sv.ho[0]>k->sv.ho[0])
				{
					swap(p->sv,k->sv);
				}
			}
			if(p->sv.ten[0]>k->sv.ten[0])
			{
				swap(p->sv,k->sv);
			}
		}
	}
}

void swap(sinhvien &a, sinhvien &b)
{
	sinhvien tmp=a;
	a=b;
	b=tmp;
}

void input(linked_list &L)
{
	int i=0;
	while(1)
	{
		PTR p=new nodesv;
		cout<<"Nhap mssv "<<i+1<<": "<<endl;
		cin>>p->sv.mssv;
		if(p->sv.mssv<=0)
		{
			cout<<"Ket thuc nhap.\nVui long Nhan enter de quay lai menu..."<<endl;
			system("pause");
			break;
		}
		NhapChuoi( "Nhap ho: ",p->sv.ho);
		NhapChuoi( "Nhap ten: ",p->sv.ten);
		cout<<endl;
		i++;
		p=newnode(p->sv);
		insert_last(L,p);
	}
}

void xuatsv(sinhvien x)
{
	cout<<"\t"<<x.mssv<<"\t"<<x.ho<<""<<x.ten<<endl;
}

void output(linked_list L)
{
	PTR p;
	p=L.first;
	cout<<"\t\t==== DSSV ===="<<endl;
	while(p!=NULL)
	{
		xuatsv(p->sv);
		p=p->next;
	}
	cout<<endl;
	cout<<"Nhan Enter de tro lai menu..."<<endl;
	system("pause");
}

int Reccount(PTR p)
{
	int count=0;
	while(p!=NULL)
	{
		count++;
		p=p->next;
	}
	return count;
}

void insert_after_i(linked_list &l, PTR p, int vt)
{
	if(l.first==NULL||vt==0)
	{
		insert_first(l,p);
	}
	else if(vt>Reccount(l.first))
	{
		insert_last(l,p);
	}
	else
	{
		int count=0;
		for(PTR k=l.first;k!=NULL;k=k->next)
		{
			count++;
			if(count==vt)
			{
				p->next=k->next;
				k->next=p;
			}
		}
	}
}

void delete_first(linked_list &L)
{
	if(L.first==NULL)
	{
		return;
	}
	PTR p=L.first;
	L.first=p->next;
	delete p;
}

void delete_last(linked_list &L)
{
	if(L.first==NULL)
	{
		return;
	}
	if(L.first->next==NULL)
	{
		delete_first(L);
		return;
	}
	for(PTR k=L.first;k!=NULL;k=k->next)
	{
		if(k->next==L.last)
		{
			delete L.last;
			k->next=NULL;
			L.last=k;
			return;
		}
	}
}

void print(linked_list L, int ms)
{
	if(L.first==NULL)
	{
		cout<<"Khong co sinh vien nao trong danh sach"<<endl;
		cout<<"\nNhan Enter de tro lai menu"<<endl;
		system("pause");
		return;
	}
	
	for(PTR k=L.first;k!=NULL;k=k->next)
	{
		if(k->sv.mssv==ms)
		{
			cout<<"Ho ten sinh vien can tim: "<<k->sv.ho<<k->sv.ten<<endl;
			cout<<"\nNhan Enter de tro lai menu"<<endl;
			system("pause");
			return;
		}
	}
	cout<<"Khong tim duoc sinh vien co ma so da nhap"<<endl;
	cout<<"\nNhan Enter de tro lai menu"<<endl;
	system("pause");
}

void remove(linked_list &L, int ms)
{
	if(L.first==NULL)
	{
		cout<<"Khong co du lieu trong danh sach"<<endl;
		cout<<"\nNhan Enter de tro lai menu"<<endl;
		system("pause");
		return;
	}
	
	char kt;
	if(L.first->sv.mssv==ms)
	{
		cout<<"Y. xoa\t\tN.Khong xoa"<<endl;
		cout<<"Ban that su muon xoa? (Y/N): ";
		cin>>kt;
		if(kt=='Y')
		{
			delete_first(L);
			cout<<"Da xoa xong"<<endl;
		}
	}
	else if(L.last->sv.mssv==ms)
	{
		cout<<"Y. xoa\t\tN.Khong xoa"<<endl;
		cout<<"Ban that su muon xoa? (Y/N): ";
		cin>>kt;
		if(kt=='Y')
		{
			delete_last(L);
			cout<<"Da xoa xong"<<endl;
		}
	}
	else
	{
		PTR g;
		for(PTR k=L.first;k!=NULL;k=k->next)
		{
			if(k->sv.mssv==ms)
			{
				cout<<"Y. xoa\t\tN.Khong xoa"<<endl;
				cout<<"Ban that su muon xoa? (Y/N): ";
				cin>>kt;
				if(kt=='Y')
				{
					g->next=k->next;
					delete k;
					cout<<"Da xoa xong"<<endl;
				}
				break;
			}
			g=k;
		}
	}
	cout<<"\nNhan Enter de tro lai menu"<<endl;
	system("pause");
}

void filesave(linked_list &L)
{
	PTR p=L.first;
	char filename[10]="DSSV.DAT";
	ofstream file;
	file.open(filename,ios::out);
	while(p!=NULL)
	{
		file<<p->sv.mssv<<endl;
		file<<p->sv.ho<<endl;
		file<<p->sv.ten<<endl;
		p=p->next;
	}
	file.close();
	cout<<"Da luu vao file, nhan enter de tro lai menu..."<<endl;
	system("pause");
}

void fileload(linked_list &L)
{
	sinhvien x;
	char filename[10]="DSSV.DAT";
	PTR p;
	ifstream filein;
	filein.open(filename,ios::in);
	
	if(L.first!=NULL)
	{
		for(PTR k=L.first;k!=NULL;k=k->next)
		{
			delete_first(L);
		}
	}
	
	while(!filein.eof())
	{
		filein>>x.mssv;
		filein>>x.ho;
		filein>>x.ten;
		p=newnode(x);
		insert_last(L,p);
	}
	delete_last(L);
	filein.close();
	cout<<"Da nap du lieu xong, nhan Enter de tro lai menu..."<<endl;
	system("pause");
}

int main()
{
	bool check = true;
	int option=0;
	linked_list L;
	Khoi_tao(L);
	
	while(check == true)
	{
		system("cls");
						cout<<"======================= MENU ======================"<<endl;
						cout<<"1. Nhap danh sach sinh vien "<<endl;
						cout<<"2. Liet ke danh sach sv"<<endl;
						cout<<"3. Xem tong so sv"<<endl;
						cout<<"4. Them sv"<<endl;
						cout<<"5. Search ten sv theo ma"<<endl;
						cout<<"6. Xoa sv trong danh sach"<<endl;
						cout<<"7. Sap xep sv theo ma so tang dan"<<endl;
						cout<<"8. Sap xep sv theo ho ten"<<endl;
						cout<<"9. Save danh sach vao file"<<endl;
						cout<<"10. Nap du lieu danh sach tu file vao bo nho"<<endl;
						cout<<"0. Exit"<<endl;
						cout<<"======================= END ======================"<<endl;
						cout<<"Hay nhap lua chon cua ban: ";
		do{
			cin>>option;
			if(option>10||option<0)
			{
				cout<<"Lua chon cua ban khong hop le.\nXin hay nhap lai (0->10)"<<endl;
			}
		}while(option>10||option<0);
//===================Thuc thi====================
		
	switch(option)
		{
			case 1:
				{
					if(L.first!=NULL)
					{
						for(PTR k=L.first;k!=NULL;k=k->next)
						{
							delete_first(L);
						}
					}
					input(L);
					break;
				}
			case 2:
				{
					output(L);
					break;
				}
			case 3:
				{
					PTR p;
					p=L.first;
					cout<<"Tong so sv trong danh sach la: "<<Reccount(p)<<endl;
					cout<<"Nhan Enter de quay lai menu..."<<endl;
					system("pause");
					break;
				}
			case 4:
				{
					int vt;
					cout<<"Nhap vi tri can them sv vao sau: ";
					do{
						cin>>vt;
						if(vt<0)
						{
							cout<<"Vui long nhap lai vi tri (>=0)"<<endl;
						}
					}while(vt<0);
					
					struct sinhvien x;
					cout<<"Nhap thong tin sv can them:"<<endl;
					cout<<"Nhap mssv: ";
					cin>>x.mssv;
					if(x.mssv<=0)
					{
						cout<<"Ket thuc nhap, vui long nhan enter de tro lai menu..."<<endl;
						system("pause");
						break;
					}
					NhapChuoi("Nhap ho: ",x.ho);
					NhapChuoi("Nhap ten: ",x.ten);
					PTR p=newnode(x);
					insert_after_i(L,p,vt);
					cout<<"\nDa them vao danh sach, nhan Enter de tro lai menu"<<endl;
					system("pause");
					break;
				}
			case 5:
				{
					int ms;
					cout<<"Nhap ma so cua sv can tim: ";
					cin>>ms;
					print(L,ms);
					break;
				}
			case 6:
				{
					int ms;
					cout<<"Nhap mssv cua sv can xoa: ";
					cin>>ms;
					remove(L,ms);
					break;
				}
			case 7:
				{
					sort_ms(L);
					cout<<"\nDa sap xep xong, nhan Enter de tro lai menu"<<endl;
					system("pause");
					break;
				}
			case 8:
				{
					sort_name(L);
					cout<<"\nDa sap xep xong, nhan Enter de tro lai menu"<<endl;
					system("pause");
					break;
				}
			case 9:
				{
					filesave(L);
					break;
				}
			case 10:
				{
					fileload(L);
					break;
				}
			default:
				{
					check=false;
					break;
				}
		}
	}
}
