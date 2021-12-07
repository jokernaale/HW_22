#ifndef PLANE_H
#define PLANE_H
#define MAX 4
typedef enum {
    PASSENGER, FREIGHT, ARMY, eNofTypes
} type;
const char *typeTitle[eNofTypes];


typedef struct {
    type type;
    char *code;

} Plane;

void initPlane(Plane *plane);

type getType();

void printPlane(const Plane *plane);

void freePlane(Plane* plane);
int checkerCode(const char* code);

#endif
