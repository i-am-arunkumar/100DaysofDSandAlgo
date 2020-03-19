typedef struct Array arr;

void die(char *s);

arr create_array(arr p_a,int p_size);
void initialize(arr *p_a, int p_size);

void append(arr *p_a, int p_element);
void insert(arr *p_a, int p_index, int p_element);
int delete(arr *p_a, int p_index);

void display(arr p_a);

void swap(int *x, int *y);

int linear_search(arr *p_a, int p_key);
int binary_search(arr *p_a, int p_key);

int get(arr *p_a, int p_index);
void set(arr *p_a, int p_index, int p_element);

int max(arr *p_a);
int min(arr *p_a);

int sum(arr *p_a);
int avg(arr *p_a);

void reverse(arr *p_a);
void rotate(arr *p_a, char r);

void insert_sort(arr *p_a, int p_element);

void is_sorted(arr *p_a);
void part(arr *p_a);