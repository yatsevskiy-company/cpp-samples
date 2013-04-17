#include <vector>
#include <iostream>
struct Task {
    bool is_completed;
    std::vector<Task *> children;

    void execute() {
    }

    void notifyAboutCompletion() {
    }

    Task() : is_completed(false) {
    }

};

std::vector<Task *> tasks;

int main(int argc, char *argv[]) {
    Task *t0 = new Task;
    Task *t1 = new Task;
    Task *t2 = new Task;

    tasks.push_back(t0);
    tasks.push_back(t1);
    tasks.push_back(t2);

    t0->children.push_back(t1);
    t1->children.push_back(t2);
    //    t2->children.push_back(t0);

    int completed = 0;

    while (completed != tasks.size()) {
        int beforeCompleted = completed;
        for (std::vector<Task *>::iterator task = tasks.begin(); task != tasks.end(); ++task) {

            bool executing = true;

            for (std::vector<Task *>::iterator child = (*task)->children.begin(); child != (*task)->children.end(); ++child) {

                if ((*child)->is_completed == false) {
                    executing = false;
                    break;
                }
            }

            if (executing) {

                (*task)->execute();
                (*task)->notifyAboutCompletion();
                ++completed;
            }
        }

        if (beforeCompleted == completed) { 
            std::cout << "error" << std::endl;
            break;
        }
    }

    return 0;
}
