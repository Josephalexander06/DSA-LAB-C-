#include <stdio.h>
#include <stdlib.h>

typedef struct Block {
    size_t size;
    int free;
    void* ptr;
    struct Block* next;
    struct Block* prev;
} Block;

Block* head = NULL;

Block* create_block(size_t size) {
    Block* b = malloc(sizeof(Block));
    b->size = size;
    b->free = 0;
    b->ptr = malloc(size);
    b->next = b->prev = NULL;
    return b;
}

void add_block(Block* b) {
    if (!head) head = b;
    else {
        Block* c = head;
        while (c->next) c = c->next;
        c->next = b;
        b->prev = c;
    }
}

void* my_malloc(size_t size) {
    for (Block* c = head; c; c = c->next)
        if (c->free && c->size >= size)
            return c->free = 0, c->ptr;

    Block* b = create_block(size);
    add_block(b);
    return b->ptr;
}

void my_free(void* ptr) {
    for (Block* c = head; c; c = c->next)
        if (c->ptr == ptr) {
            c->free = 1;
            return;
        }
    printf("Pointer not found.\n");
}

void garbage_collect() {
    Block* c = head;
    while (c) {
        Block* next = c->next;
        if (c->free) {
            free(c->ptr);

            if (c->prev) c->prev->next = c->next;
            if (c->next) c->next->prev = c->prev;

            if (c == head) {
                head = c->next;
                if (head) head->prev = NULL;   // FIXED
            }

            free(c);
        }
        c = next;
    }
}


void print_blocks() {
    int i = 1;
    for (Block* c = head; c; c = c->next, i++)
        printf("%d. %p | size=%zu | free=%s\n",
               i, c->ptr, c->size, c->free ? "YES" : "NO");
}

void* get_by_index(int idx) {
    int i = 1;
    for (Block* c = head; c; c = c->next, i++)
        if (i == idx) return c->ptr;
    return NULL;
}

int main() {
    int ch, idx;
    size_t size;
    void* ptr;

    while (1) {
        printf("\n1.Alloc  2.Free  3.GC  4.Show  5.Exit\nChoice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Size: "); scanf("%zu", &size);
            printf("Allocated: %p\n", my_malloc(size));
        }
        else if (ch == 2) {
            print_blocks();
            printf("Block no: "); scanf("%d", &idx);
            ptr = get_by_index(idx);
            if (ptr) my_free(ptr); else printf("Invalid.\n");
        }
        else if (ch == 3) {
            garbage_collect();
            printf("Garbage collected.\n");
        }
        else if (ch == 4) print_blocks();
        else if (ch == 5) return 0;
        else printf("Invalid.\n");
    }
}
