/*******************************************************************************
                   * PROJECT NAME :- TEACHER INFORMACTION & STUDENT INFORMACTION2BM 3rd PROJECT
                   * 2BM V3 PROJECT
                   * ASSALAMU ALAIKUM WA RAHMATULLAH
                   * MY ID IS-----C213090-------
********************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int student_c=0,n=0,teacher_c=0;
int m=0,w1,m1,b1;
double ar[1000];
string c,id_cr;

class student

{
    string student_name,ID,sem,sec,student_tec;

public:

    student()
    {

    }

    student(string student_name, string ID,string sem,string sec,string student_tec)
    {
        this-> student_name=student_name;
        this-> ID=ID;
        this-> sem=sem;
        this-> sec=sec;
        this-> student_tec=student_tec;
    }
    void get_data()
    {
        cout<< " STUDENT NAME :  "<<student_name<<endl;
        cout<< " STUDENT ID : "<<ID<<endl;
        cout<< " STUDENT SEMESTER : "<<sem<<endl;
        cout<< " STUDENT Section  : "<<sec<<endl;
        cout<< " TEACHER NAME : "<<student_tec<<endl;
    }
    string Id()
    {
        return ID;
    }
    friend void read_std_info();
    friend void write_std_info();
    friend void add_std_info();
    friend void search_std_info();
    friend void edit_std_info();
    friend void delete_std_info();
    friend void check_result();
    friend void tec_result();
}

student_arr[1000];

void write_std_info()

{
    fstream write("C213090_.txt",ios::out);

    write<<student_c<<endl;

    for(int i=0;i<student_c;i++)
    {
        write<<student_arr[i].student_name<<endl;
        write<<student_arr[i].ID<<endl;
        write<<student_arr[i].sem<<endl;
        write<<student_arr[i].sec<<endl;
        write<<student_arr[i].student_tec<<endl;
    }

    write.close();
}

void read_std_info()

{

    fstream read("C213090_.txt",ios::in);
    read>>student_c;

    for(int i=0; i<student_c; i++)
    {
        read >> student_arr[i].student_name;
        read >> student_arr[i].ID;
        read >> student_arr[i].sem;
        read >> student_arr[i].sec;
        read >> student_arr[i].student_tec;
        read << endl;
    }

    read.close();
}

void addstudent_information()

{
    read_std_info();
    cout<<"\t\t  Total Student : ";
    cin>>n;
    int n1=1;
    student_c+=n;
    for(int i=student_c; i<(student_c+n); i++)
    {
        string std_name,ID,sem,sec,std_tec;
        cout<<endl;
        cout << "\t Enter Information Of Student Number : " <<n1<<endl;

        cout << "\t Enter Student Name    : ";
        cin >> std_name;
        cout << "\t Enter Sudent ID       : ";
        cin >> ID;
        cout << "\t Enter Semester        : ";
        cin >> sem;
        cout << "\t Enter Section         : ";
        cin >> sec;
        cout << "\t  Enter Teacher's Name : ";
        cin>>std_tec;
        student_arr[i] = student(std_name, ID, sem, sec, std_tec);
        cout<<endl;
        n1++;
    }
    student_c+=n;
    write_std_info();
}
void search_std_info()
{
    read_std_info();

    if(student_c==0)
    {
        cout<<"\t No Student Information Inserted"<<endl;
    }
    else
    {
        string ID;
        int x=0;
        cout<<endl;
        cout<<"\t Enter ID : ";
        cin>>ID;
        cout<<endl;
        for(int i=0;i<student_c;i++)
        {
            if(ID ==student_arr[i].Id())
            {
                student_arr[i].get_data();
                x=1;
                break;
            }
        }
        if(x==0)
        {
            cout<<"\t Data Not Found!"<<endl<<"\t Returned To Main Menu"<<endl;
        }
    }
}
void edit_std_info()
{
    read_std_info();
    if(student_c==0)
    {
        cout<<"\t No Student Info Inserted"<<endl;
    }
    else
    {
        string ID;
        int x=0;
        cout<<endl;
        cout<<"\t  Enter ID : ";
        cin>>ID;
        cout<<endl;
        for(int i=0;i<student_c;i++)
        {
            if(ID  ==  student_arr[i].Id())
            {
                x=1;
                string std_name,ID,sem,sec,std_tec;
                cout<<endl;
                cout << "\t Enter info of student number : " << i+1 <<endl;
                cout << "\t Enter Name : ";
                cin >> std_name;
                cout << "\t Enter Metric ID : ";
                cin >> ID;
                cout << "\t Enter Semester : ";
                cin >> sem;
                cout << "\t Enter Section : ";
                cin >> sec;
                cout<<"\t Enter Teacher's Name : ";
                cin>>std_tec;
                student_arr[i] = student(std_name, ID, sem, sec, std_tec);
                cout<<endl;
                break;
            }
        }
        if(x==0)
        {
            cout<<"\t Data Not Found!"<<endl<<"\t Returned To Main Menu"<<endl;
        }
        else{
            cout<<"\t Successfully Edited Info Of : "<<ID<<endl<<endl;
        }
    }

    write_std_info();
}
void delete_std_info()
{
    read_std_info();
    if(student_c==0)
    {
        cout<<"\t No Student Info Inserted"<<endl;
    }
    else
    {
        string ID;
        int p=0,change;
        cout<<endl;
        cout<<"\t Enter ID : ";
        cin>>ID;
        cout<<endl;
        for(int i=0;i<student_c;i++)
        {
            if(ID==student_arr[i].Id())
            {
                p=1;
                change=i;
            }
        }
        if(p==0)
        {
            cout<<"\t Data Not Found!    Returned To Main Menu"<<endl;
        }
        else{
            for(int i=change;i<student_c;i++)
            {
                student_arr[i]      = student_arr[i+1];
            }

            student_c-=1;

            cout<<"\tSuccessfully Deleted!"<<endl<<endl;
        }
    }
    write_std_info();
}
class teacher
{
    string name,ID,dept,des;
public:
    teacher()
    {}
    teacher(string name,string ID,string dept,string des)
    {
        this->name=name;
        this->ID=ID;
        this->dept=dept;
        this->des=des;
    }
    void tec_get()
    {
        cout<<"\t Teacher Name        : "<<name<<endl;
        cout<<"\t Teacher ID          : "<<ID<<endl;
        cout<<"\t Department          : "<<dept<<endl;;
        cout<<"\t Designation         : "<<des<<endl<<endl;
    }
    string Id()
    {
        return ID;
    }
    friend void read_tec_info();
    friend void write_tec_info();
    friend void add_tec_info();
    friend void search_tec_info();
    friend void edit_tec_info();
}

teacher_arr[1000];

void write_tec_info()
{
    fstream write("C213090_.txt",ios::out);
    write<<teacher_c<<endl;
    for(int i=0;i<teacher_c;i++)
    {
        write<<teacher_arr[i].name<<endl;
        write<<teacher_arr[i].ID<<endl;
        write<<teacher_arr[i].dept<<endl;
        write<<teacher_arr[i].des<<endl;
    }
    write.close();
}
void read_tec_info()
{
    fstream read("C213090_.txt",ios::in);
    read>>teacher_c;
    for(int i=0;i<teacher_c;i++)
    {
        read >> teacher_arr[i].name;
        read >> teacher_arr[i].ID;
        read >> teacher_arr[i].dept;
        read >> teacher_arr[i].des;
    }
    read.close();
}
void add_tecacher_info()
{
    read_tec_info();
    cout<<" "<<endl;
    cout<<"       Total Teacher : ";
    cin>>m;
    int m1=1;

    for(int i=teacher_c;i<(teacher_c+m);i++)
    {
        string name,ID,dept,des;
        cout<<endl;
        cout<<"\t Enter Info Of Teacher No : "<<m1<<endl;
        cout<<" "<<endl;
        cout << "\t Enter Teacher Name     : ";
        cin >> name;
        cout<<" "<<endl;
        cout << "\t Enter Teacher ID       : ";
        cin >> ID;
        cout<<" "<<endl;
        cout << "\t Enter Department       : ";
        cin >> dept;
        cout<<" "<<endl;
        cout << "\t Enter Designation      : ";
        cin >> des;

        teacher_arr[i] = teacher(name, ID, dept, des);

        cout<<endl;
        m1++;

    }

    teacher_c+=m;
    write_tec_info();

}
void search_tecacher_info()
{
    read_tec_info();

    if(teacher_c==0)

    {
        cout<<"\t No Teacher Info Inserted"<<endl;
    }

    else
    {
        string ID;
        int y=0;
        cout<<endl;
        cout<<"\tEnter ID : ";
        cin>>ID;
        cout<<endl;

        for(int i=0;i<teacher_c;i++)
        {
            if(ID == teacher_arr[i].Id())
            {
                teacher_arr[i].tec_get();
                y=1;
                break;
            }
        }

        if(y==0)
        {
            cout<<"\t Invalid Data Not Found!"<<endl<<"\t Returned To Main Menu"<<endl;
        }
    }
}

void edit_tecacher_info()

{
    read_tec_info();

    if(teacher_c==0)
    {
        cout<<"\t No Teacher Info Inserted "<<endl;
    }

    else
    {
        string ID;
        int y=0;
        cout<<endl;
        cout<<"\t Enter ID : ";
        cin>>ID;
        cout<<endl;
        for(int i=0;i<student_c;i++)
        {
            if(ID==teacher_arr[i].Id())
            {
                y=1;
                string name,ID,dept,des;
                cout<<endl;
                cout<<"\t Enter Info Of Teacher No : "<<i+1<<endl;
                cout << "\t Enter Name : ";
                cin >> name;
                cout << "\t Enter ID : ";
                cin >> ID;
                cout << "\t Enter Department : ";
                cin >> dept;
                cout << "\t Enter Designation : ";
                cin >> des;
                teacher_arr[i] = teacher(name, ID, dept, des);
                cout<<endl;
            }
        }
        if(y==0){
            cout<<"\t\t Invalid Data Not Found!"<<endl<<"\t\t Returned To Main Menu"<<endl;
        }
        else{
            cout<<"\t Successfully Edited Information Of : "<<ID<<endl;
        }
    }

    write_tec_info();
}

void check_result()

{
    string ID;
    cout<<"\t\t  Enter ID : ";
    cin>>ID;
    cout<<endl;
    for(int i=0;i<student_c;i++)
    {
        if(ID == student_arr[i].Id())

        {
            if(ar[i]!=0)
            {
                student_arr[i].get_data();

                printf("\t CGPA        : %.2lf\n\n",ar[i]);

                break;
            }
            else
            {
                cout<<"\t Result Not Yet Available!"<<endl<<endl;
                break;
            }

        }
    }
}


void teacher_result()

{
    string ID;
    int fail=0;
    cout<<"\t Enter ID : ";
    cin>>ID;
    for(int i=0;i<student_c;i++)
    {
        if(ID == student_arr[i].Id())
        {

            {
                student_arr[i].get_data();
                cout<<"\t  Enter Result   : ";
                cin>>ar[i];
                cout<<endl;
                fail=1;
                break;
            }
        }
    }


    if(fail==0)
    {
        cout<<"\t INVALID ID  !!"<<endl<<endl;
    }

}

int main()

{

    ifstream check_std_file("C213090_std.txt");

    if(!check_std_file)

    {
        fstream open_file_std("C213090_std.txt, ios::app");
        {
            open_file_std << 0 <<endl;
        }
    }

    ifstream check_tec_file("C213090_tec.txt");

    if(!check_tec_file)

    {
        fstream open_file_tec("C213090_tec.txt, ios::app");
        {
            open_file_tec << 0 <<endl;
        }
    }



    cout<<" "<<endl;

    cout<<"==================================  Bismillahir Rahmanir Rahim ==============================\n"<<endl;

    cout <<"=================================        Welcome to IIUC  =============================== \n"<< endl;

    cout <<"=================================        PROJECT : V3    =============================== \n"<< endl;

    while(1)

    {

        int z,k;
        cout<<"       ENTER 1  ----------------   STUDENT INFORMATION "<<endl;
        cout<<" "<<endl;
        cout<<"       ENTER 2  ----------------   TEACHER INFORMATION "<<endl;

        cout<<" "<<endl;
        cout<<"       ENTER "<<endl;
        cout<<endl;
        cout<<"       Enter : ";
        cin>>z;

        w1=m1=0;

        if(z==0)

        {
            cout<<endl<<"\t  Exited Successfully!!"<<endl;
            return 0;
        }
        else if(z==1)

        {

            while(1)
            {
                cout<<endl;
                cout<<"\t 1  Add New Students "<<endl;
                cout<<"\t 2  Search Student Info"<<endl;
                cout<<"\t 3  Edit Student Data"<<endl;
                cout<<"\t 4  Delete Student Data"<<endl;
                cout<<"\t 5  See Result"<<endl;
                cout<<"\t 0  Main Menu"<<endl;
                cout<<endl<<"\t   Enter : ";


                cin>>k;

                if(k==0){
                    break;
                }
                else if(k==1)
                {
                    addstudent_information();
                }
                else if(k==2)
                {
                   search_std_info();
                }
                else if(k==3){
                    edit_std_info();
                }
                else if(k==4)
                {
                    delete_std_info();
                }
                else if(k==5)
                {
                    check_result();
                }
            }
        }


        else if(z==2)

        {

            while(1)

            {
                int k;
                cout<<"\t 1  Add New Teacher"<<endl;
                cout<<"\t 2  Search Teacher's Info"<<endl;
                cout<<"\t 3  Edit Teacher's Info"<<endl;
                cout<<"\t 4  Result Processing"<<endl;
                cout<<"\t 0  Main Menu"<<endl<<endl;
                cout<<"\t    Enter : ";

                cin>>k;

                if(k==0)
                {
                    break;
                }

                else if(k==1)
                {
                    add_tecacher_info();
                }

                else if(k==2)
                {
                    search_tecacher_info();
                }
                else if(k==3)
                {
                    edit_tecacher_info();
                }

                else if(k==4)

                {
                    teacher_result();

                }



            }



        }
    }
}



