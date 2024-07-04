#include<iostream>
#include<fstream>
using namespace std;
class File
{
private:
    int base_data;
public:
    void set_data(int data)
    {
        base_data = data;
    }
    int get_data()
    {
        return base_data;
    }
};
int main()
{
    int i,n;
    File obj[3],arr[3];
    for(i=0;i<3;i++)
    {
        cout<<"Enter Data"<<endl;
        cin>>n;
        obj[i].set_data(n);
    }
    ofstream fout("name.dat",ios::binary);
    ifstream fin("name.dat",ios::binary);
    if(!fout && !fin)
    {
        cerr<<"File Creation Failed"<<endl;
        return 1;
    }
    fout.write(reinterpret_cast<char*>(obj),3 * sizeof(File));
    fout.close();
    fin.read(reinterpret_cast<char*>(arr), 3 * sizeof(File));
    cout<<arr[0].get_data()<<endl;
    cout<<arr[1].get_data()<<endl;
    cout<<arr[2].get_data()<<endl;
    fin.close();
    return 0;
}
