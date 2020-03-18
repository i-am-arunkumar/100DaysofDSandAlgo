typedef struct Array arr;

void die(char *s);
arr create_array(arr p_a,int p_size);
void initialize(arr *p_a, int p_size);
void append(arr *p_a, int p_element);
void insert(arr *p_a, int index, int p_element);
void display(arr p_a);