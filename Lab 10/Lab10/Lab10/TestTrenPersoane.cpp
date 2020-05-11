#include "TestTrenPersoane.h"
#include <assert.h>
#include "TrenPersoane.h"
#include "Util.h"

void TestTrenPersoane::testAll()
{
	this->testImplicitConstructor();
	this->testConstructorWithParameters();
	this->testCopyConstructor();
	this->testClone();
	this->testGetLocuri();
	this->testSetLocuri();;
	this->testAssignmentOperator();
	this->testEqualityOperator();
	this->testToString();
}

void  TestTrenPersoane::testImplicitConstructor()
{
	TrenPersoane p;
	assert(p.getModel().empty());  assert(p.getProducator().empty());
	assert(p.getNr() == 0);
	assert(p.getLibere() == 0);
	assert(p.getOcupate() == 0);
}

void  TestTrenPersoane::testConstructorWithParameters()
{
	TrenPersoane p("CF", "MODEL", 55, 3, 2, 1);
	assert(p.getModel() == "CF");
	assert(p.getProducator() == "MODEL");
	assert(p.getLocuri() == 55);
	assert(p.getNr() == 3);
	assert(p.getLibere() == 2);
	assert(p.getOcupate() == 1);
}

void  TestTrenPersoane::testCopyConstructor()
{
	TrenPersoane p1("CF", "MODEL", 55, 3, 2, 1);
	TrenPersoane p2(p1);
	assert(p2.getModel() == p1.getModel());
	assert(p2.getProducator() == p1.getProducator());
	assert(p2.getNr() == p1.getNr());
	assert(p2.getLibere() == p1.getLibere());
	assert(p2.getOcupate() == p1.getOcupate());
	assert(p2.getLocuri() == p1.getLocuri());
}

void  TestTrenPersoane::testClone()
{
	TrenPersoane p("CF", "MODEL", 55, 3, 2, 1);
	TrenPersoane* pClone = (TrenPersoane*)p.clone();
	assert(p == *pClone);
	assert(&p != pClone);
}

void  TestTrenPersoane::testGetLocuri()
{
	TrenPersoane p1("CF", "MODEL", 55, 3, 2, 1);
	assert(p1.getLocuri() == 55);
}

void  TestTrenPersoane::testSetLocuri()
{
	TrenPersoane p1("CF", "MODEL", 55, 3, 2, 1);
	p1.setLocuri(53);
	assert(p1.getLocuri() == 53);
}

void  TestTrenPersoane::testAssignmentOperator()
{
	TrenPersoane p1("CF", "MODEL", 55, 3, 2, 1);
	TrenPersoane p2(p1);
	assert(p2.getModel() == p1.getModel());
	assert(p2.getProducator() == p1.getProducator());
	assert(p2.getNr() == p1.getNr());
	assert(p2.getLibere() == p1.getLibere());
	assert(p2.getOcupate() == p1.getOcupate());
	assert(p2.getLocuri() == p1.getLocuri());
}

void  TestTrenPersoane::testEqualityOperator()
{

	TrenPersoane p1("CF", "MODEL", 55, 3, 2, 1);
	TrenPersoane p2 = p1;
	assert(p1 == p2);
	p2.setModel("bruosa");
	assert(!(p1 == p2));
	p2.setModel(p1.getModel());
	assert(p1 == p2);
	p2.setProducator("pr");
	assert(!(p1 == p2));
	p2.setProducator(p1.getProducator());
	assert(p1 == p2);
	p2.setNrVag(33);
	assert(!(p1 == p2));
	p2.setNrVag(p1.getNr());
	assert(p1 == p2);
	p2.setOcupate(33);
	assert(!(p1 == p2));
	p2.setOcupate(p1.getOcupate());
	assert(p1 == p2);
	p2.setLibere(33);
	assert(!(p1 == p2));
	p2.setLibere(p1.getLibere());
	assert(p1 == p2);
	p2.setLocuri(33);
	assert(!(p1 == p2));
	p2.setLocuri(p1.getLocuri());
	assert(p1 == p2);

}

void  TestTrenPersoane::testToString()
{
	TrenPersoane p1("CF", "MODEL", 55, 3, 2, 1);
	assert(p1.toString(" ") == "TP CF MODEL 3 2 1 55");
	assert(p1.toString(",") == "TP,CF,MODEL,3,2,1,55");
}
