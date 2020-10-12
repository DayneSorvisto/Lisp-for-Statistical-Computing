#define PAD 1
#define MESSAGE_LENGTH 23

typedef struct {
char message[MESSAGE_LENGTH];
int rows;
int cols;

} header;

void print_header(header program_header);