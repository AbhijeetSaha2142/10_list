struct pokemon{
    char name[256];
    int speed;
    struct pokemon *next;
};

struct pokemon * new_pokemon(int spd, char * n);

void print_stats(struct pokemon *p);

void modify_stats(struct pokemon *p, int spd, char * n);

void print_list(struct pokemon *p);

struct pokemon * insert_front(struct pokemon *p, int spd, char *n);

struct pokemon *free_list(struct pokemon *p);

struct pokemon *remove_node(struct pokemon *p, int spd, char *n);

