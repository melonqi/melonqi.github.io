#include <iostream>
#include <pthread.h>
#include <vector>
using namespace std;

void *func(void *args)
{
    vector<int> *vec = (vector<int>*) args;
    cout<<"vec size:"<<vec->size()<<endl;
    for(vector<int>::iterator it = vec->begin();it!=vec->end();it++)
    {
        cout<<*it<<endl;
    }

}

int main()
{
    pthread_t thread_ids[2];
    for(int i=0;i<2;i++)
    {
         //new出来的变量出循环不会被释放，但是什么时候delete？
        vector<int> *vec = new vector<int>();
       
        for(int j=0;j<3;j++)
        {
            vec->push_back(i*j);
        }

        int ret=pthread_create(&thread_ids[i],NULL,func,(void*)vec);
        if(ret!=0)
        {
            cout<<"Create Thread Fail!"<<endl;
            return -1;
        }
    }

    for(int i=0;i<2;i++)
    {
        pthread_join(thread_ids[i],NULL);//等待线程结束
    }

    return 0;
}
