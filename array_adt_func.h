typedef struct Array arr;

void die(char *s);
arr create_array(arr p_a,int p_size);
void initialize(arr *p_a, int p_size);
void append(arr *p_a, int p_element);
void insert(arr *p_a, int p_index, int p_element);
void display(arr p_a);
int delete(arr *p_a, int p_index);
void swap(int *x, int *y);
int linear_search(arr *p_a, int p_key);
int binary_search(arr *p_a, int p_key);