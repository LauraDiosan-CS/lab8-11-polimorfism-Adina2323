
#include <iostream>
#include "RepoFile.h"
#include "RepoFileTXT.h"
#include "RepoFileCSV.h"
#include "TestRepo.h"
#include "TestTren.h"
#include "TestTrenPersoane.h"
#include "TestTrenMarfa.h"
#include "UI.h"
int main()
{
    TestTren testTren;
    testTren.testAll();
    TestTrenMarfa testTrenMarfa;
    testTrenMarfa.testAll();
    TestTrenPersoane testTrenPersoane;
    testTrenPersoane.testAll();

    TestRepo testRepoFile;
    testRepoFile.testAll();

    RepoFile* repoFile;
    string option;
    UI ui;
    ui.login();
    option = "txt";
    if (option == "txt")
    {
        repoFile = new RepoFileTXT("fisier.txt");
    }
    else
    {
        if (option == "csv")
        {
            repoFile = new RepoFileCSV("fisier.txt");
        }
    }
}