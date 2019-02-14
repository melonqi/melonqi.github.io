#include <iostream>
#include <pthread.h>
#include <vector>
#include <zconf.h>

using namespace std;

void *func(void *args) {
    int *val = (int *)args;
    sleep(1);//使效果更明显
    cout<<*val<<endl;
}

int main() {

    pthread_t thread_ids[5];

    vector<int> vec;
    for (int i = 0; i < 5; i++) {
        cout<<"capactity:"<<vec.capacity()<<endl;
        vec.push_back(i);
        int ret = pthread_create(&thread_ids[i], NULL, func, (void *) &(vec[i]));
        if (ret != 0) {
            cout << "Create Thread Fail!" << endl;
            return -1;
        }

    }

    for(int i=0;i<5;i++)
    {
        pthread_join(thread_ids[i], NULL);//等待线程结束
    }

    return 0;
}
