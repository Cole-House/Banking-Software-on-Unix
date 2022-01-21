class llist
{
private:
    record *    start;
    char        filename[16];
    int         readfile();
    int         writefile();
    void        cleanup();

public:
    llist();
    llist(char[]);
    ~llist();
    int addRecord(int, char [ ],char [ ]);
    int findRecord(int);
    void printAllRecords();
    int deleteRecord(int);
};
