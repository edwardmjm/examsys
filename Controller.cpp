#include "Controller.h"
#include <QDebug>
#include <QFile>
#include <iostream>
using namespace std;

//修改题库
void Controller::addProblem(const Problem &p) {
    questionBank.push_back(p);
}

void Controller::editProblem(int index, const Problem &p) {
    questionBank[index] = p;
}

void Controller::removeProblem(int index) {
    questionBank.erase(questionBank.begin() + index);
}

//修改试卷
void Controller::addPaper(const Paper &l) {
    paper.push_back(l);
}

void Controller::editPaper(int index, const Paper &l) {
    paper[index] = l;
}

void Controller::removePaper(int index) {
    paper.erase(paper.begin() + index);
}

//修改答卷
void Controller::addResult(const Result &res) {
    result.push_back(res);
    res.printInfo();
}

void Controller::editResult(int index, const Result &res) {
    result[index] = res;
}

void Controller::removeResult(int index) {
    result.erase(result.begin() + index);
}

std::vector <Problem> & Controller::getQuestionBank() {
    return questionBank;
}

std::vector <Paper> & Controller::getPaper() {
    return paper;
}

std::vector <Result> & Controller::getResult() {
    return result;
}

QStringList Controller::getPaperQStringList() {
    QStringList res;
    for (size_t i = 0; i < paper.size(); i++) {
        res.append(paper[i].getTitle());
    }
    return res;
}

void Controller::save() {
    int a, b, c;
    int i;
    a=questionBank.size();
    b=paper.size();
    c=result.size();

    QFile file("/tmp/examsys.dat");
    if(!file.open(QIODevice::WriteOnly)) {
        std::cerr<<"Cannot open the file"
        <<qPrintable(file.errorString())
        <<std::endl;
        return;
    }

    QDataStream out(&file);
    out << a;
    for(i = 0; i < a; i++) {
        out << questionBank[i];
    }

    out << b;
    for(i = 0; i < b; i++) {
        out << paper[i];
    }

    out << c;
    for(i = 0; i < c; i++) {
        out << result[i];
    }
}

void Controller::load() {
    int a, b, c;
    int i;
    QFile file("/tmp/examsys.dat");
    if (!file.open(QIODevice::ReadOnly)) {
             std::cerr << "Cannot open file for reading: "
                       << qPrintable(file.errorString()) << std::endl;
        return;
    }

    QDataStream in(&file);
    in >> a;
    questionBank.resize(a);
    for(i = 0; i < a; i++) {
       in >> questionBank[i];
    }

    in >> b;
    paper.resize(b);
    for(i = 0; i < b; i++) {
       in >> paper[i];
    }

    in >> c;
    result.resize(c);
    for(i = 0; i < c; i++) {
       in >> result[i];
    }
}

