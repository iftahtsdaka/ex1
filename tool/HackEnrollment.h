#ifndef EX1_HACKENROLLMENT_H
#define EX1_HACKENROLLMENT_H
#include "../IsraeliQueue.h"
#include "Student.h"
#include <stdio.h>

typedef struct Course{
    IsraeliQueue course_queue;
    int course_number;
    int size;
}*Course;

//I thought to use indexes to put the object in their place in the array but then we need to allocate
//Every time or to go through the file twice to see how many students/hackers/courses there are.
//Or we can do linked list ("reshima mekusheret")
typedef struct EnrollmentSystem{
    Course* courses;
    int index_courses;
    Student* students;
    int index_students;
    Hacker* hackers;
    int index_hackers;
}*EnrollmentSystem;

//creates an Enrollment System that will contain the data from the files
EnrollmentSystem createEnrollment(FILE* students, FILE* courses, FILE* hackers);
//

//reading the file into enrollment system
EnrollmentSystem readEnrollment(EnrollmentSystem sys, FILE* queues);
//

//putting the hackers from the file in the courses they asked
void hackEnrollment(EnrollmentSystem sys, FILE* out);

//parse line to course
Course parseLineToCourse(char* line);

//returns the sum differences between ascii characters of two names (Friendship Function)
int nameDifferences(void*, void*);

//returns the difference between two ID (Friendship Function)
int idDifferences(void*, void*);

//return friendship score of 20 if student is in student_hacker friend list, -20 if in rival list, 0 otherwise. (Friendship Function)
int isFriendOrRival(void*, void*);

//Israeli queue comparison function
int compareId(void*, void*);

//Loads all students from students file to the enrollment system
void putStudentInEnrollment(FILE* students, EnrollmentSystem enrollmentSystem);

//Loads all courses from students file to the enrollment system
void putCoursesInEnrollment(FILE* courses, EnrollmentSystem enrollmentSystem);

//Loads all hackers from students file to the enrollment system
void putHackersInEnrollment(FILE* hackers, EnrollmentSystem enrollmentSystem);
//get the length of a file
int getNumOfLines(FILE* file_to_read);
//allocate an enrollment system
EnrollmentSystem mallocEnrollmentSystem(FILE* students, FILE* courses, FILE* hackers);
//returns the max line length in the file
int getMaxLineLength(FILE* file_to_read);
//returns the max string length int the file
int getMaxStrLength(FILE* file_to_read);

//find student in enrollment by his id
Student findStudentById(EnrollmentSystem sys, char* id);
//adjust hacker to student in the ins_hacker pointer
void adjustHackerToStudent(EnrollmentSystem sys);

void destroyEnrollment(EnrollmentSystem sys);
void writeEnrollmentQueue(FILE* out, Course course);

Hacker hackerLeftOut(EnrollmentSystem sys);

bool hackerGotIn(Hacker hacker, EnrollmentSystem sys);

bool studentInCourse(Student student, Course course);

IsraeliQueueError enqueueHacker(Hacker hacker, EnrollmentSystem sys);

Course getCourse(int course_number, EnrollmentSystem sys);

bool isHackerRival(Hacker hacker, Student student);

bool isHackerFriend(Hacker hacker, Student student);
void destroyCourse(Course course);


#endif //EX1_HACKENROLLMENT_H
