struct figure
{
    int Square;
    char *Name;

    union Params
    {
        float Perimeter;
        char Color[7];
        // #pragma pack(push, 1)
        struct {
            // unsigned : 10;
            // unsigned : 10;
            // unsigned : 10;
            // unsigned : 10;

            unsigned : 32;
            unsigned : 8;
            char flag: 8;
        };
    } params;
};

void viewData(struct figure* f, int num);