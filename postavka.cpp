#include<iostream>
#include<vector>
using namespace std;

/****************************************************************************
1. SVE KLASE TREBAJU POSJEDOVATI ADEKVATAN DESTRUKTOR
2. NAMJERNO IZOSTAVLJANJE KOMPLETNIH I/ILI POJEDINIH DIJELOVA DESTRUKTORA KOJI UZROKUJU RUNTIME ERROR ?E BITI OZNACENO KAO "RE"
3. SPAŠAVAJTE PROJEKAT KAKO BI SE SPRIJE?ILO GUBLJENJE URA?ENOG ZADATKA
4. NAZIVI FUNKCIJA, TE BROJ I TIP PARAMETARA MORAJU BITI IDENTI?NI ONIMA KOJI SU KORIŠTENI U TESTNOM CODE-U, OSIM U SLU?AJU DA POSTOJI ADEKVATAN RAZLOG ZA NJIHOVU MODIFIKACIJU. OSTALE, POMO?NE FUNKCIJE MOŽETE IMENOVATI I DODAVATI PO ŽELJI.
5. IZUZETAK BACITE U FUNKCIJAMA U KOJIMA JE TO NAZNA?ENO.
****************************************************************************/
const char* crt = "\n-------------------------------------------\n";
const char* not_set = "NOT_SET";

char* AlocirajNizKaraktera(const char* sadrzaj) {
	if (sadrzaj == nullptr)
		return nullptr;
	int vel = strlen(sadrzaj) + 1;
	char* temp = new char[vel];
	strcpy_s(temp, vel, sadrzaj);
	return temp;
}

template<class T1, class T2>
class Kolekcija {
	T1* _elementi1=nullptr;
	T2* _elementi2=nullptr;
	int* _trenutno=nullptr;
public:
	Kolekcija() {
		_trenutno = new int(0);
	}

	//implementirati copy ctor
	Kolekcija(const Kolekcija& obj)
	{
		
	}
	//implementirati operator dodjele
	Kolekcija& operator=(const Kolekcija& obj)
	{
		
		return *this;
	}

	~Kolekcija() {
		delete[] _elementi1; _elementi1 = nullptr;
		delete[] _elementi2; _elementi2 = nullptr;
		delete _trenutno; _trenutno = nullptr;
	}
	T1* getElementi1Pok() { return _elementi1; }
	T2* getElementi2Pok() { return _elementi2; }
	T1& getElement1(int lokacija) const {
		if (lokacija < 0 || lokacija >= *_trenutno)
			throw exception("Nevalidna lokacija");
		return _elementi1[lokacija]; 
	}
	T2& getElement2(int lokacija) const {
		if (lokacija < 0 || lokacija >= *_trenutno)
			throw exception("Nevalidna lokacija");
		return _elementi2[lokacija]; 
	}
	int getTrenutno() const { 
		if (_trenutno == nullptr)
			return 0;
		return *_trenutno; 
	}

	friend ostream& operator<<(ostream& COUT, Kolekcija<T1, T2>& obj) {
		for (size_t i = 0; i < obj.getTrenutno(); i++)
			COUT << obj.getElement1(i) << " " << obj.getElement2(i) << endl;
		return COUT;
	}

	//potrebno je implementirati funkciju Add za klasu kolekcija na nacin da se svaki novi el1 doda na kraj niza _elemnti1, a svaki novi el2 na kraj niza _elementi2
	//voditi racuna o tome da prije dodavanja novih elementa treba prosiriti velcinu nizova bez gubljenja prethodno spremljenjih vrijednosti
	void Add(T1 el1, T2 el2)
	{
		
	}
};
class Poglavlje {
	char* _naslov;
	char* _sadrzaj;
	bool _prihvaceno;
	int _ocjena;//da bi se poglavlje smatralo prihvacenim ocjena mora biti u opsegu od 6 - 10
public:
	//zavrsiti implementaciju user-def. ctor-a
	Poglavlje(const char* naslov = nullptr, const char* sadrzaj = nullptr) : _ocjena(0), _prihvaceno(false) {
		
	}
	//implementirati copy ctor
	Poglavlje(const Poglavlje& obj)
	{
		
	}
	//implementirati operator dodjele
	Poglavlje& operator=(const Poglavlje& obj)
	{
		
		return *this;
	}

	~Poglavlje() {
		delete[] _naslov; _naslov = nullptr;
		delete[] _sadrzaj; _sadrzaj = nullptr;
	}

	friend ostream& operator<<(ostream& COUT, Poglavlje& obj) {
		if (obj._naslov == nullptr || obj._sadrzaj == nullptr)
			return COUT;
		COUT << endl << obj._naslov << endl << obj._sadrzaj << endl;
		if (obj._prihvaceno)
			COUT << "Ocjena: " << obj._ocjena << endl;;
		return COUT;
	}
	char* GetNaslov() const{ return _naslov; }
	char* GetSadrzaj() const{ return _sadrzaj; }
	bool GetPrihvaceno() const { return _prihvaceno; }
	int GetOcjena() const{ return _ocjena; }

	void SetSadrzaj(const char* s)
	{
		delete[] _sadrzaj;
		_sadrzaj = AlocirajNizKaraktera(s);
	}

	void OcijeniPoglavlje(int ocjena) {
		_ocjena = ocjena;
		if (_ocjena > 5 && ocjena <= 10)
			_prihvaceno = true;
	}
};

class ZavrsniRad {
	char* _tema;
	vector<Poglavlje> _poglavljaRada;
	string _datumOdbrane;
	float _konacnaOcjena; //prosjek ocjena svih poglavlja u zavrsnom radu koja se izracunava u momentu zakazivanja odbrane
public:
	ZavrsniRad(const char* nazivTeme = nullptr) : _konacnaOcjena(0), _datumOdbrane(not_set), _poglavljaRada() {
		_tema = AlocirajNizKaraktera(nazivTeme);
	}

	//zavrsiti implementaciju copy ctor-a
	ZavrsniRad(const ZavrsniRad& org) : _poglavljaRada(org._poglavljaRada), _konacnaOcjena(org._konacnaOcjena), _datumOdbrane(org._datumOdbrane) {
		
	}

	~ZavrsniRad() {
		delete[] _tema; _tema = nullptr;
	}
	char* GetNazivTeme()const { return _tema; }
	vector<Poglavlje>& GetPoglavlja() { return _poglavljaRada; };
	string GetDatumOdbrane()const { return _datumOdbrane; }
	float GetOcjena() { return _konacnaOcjena; }
	void SetDatumOdbrane(string datumOdbrane) { _datumOdbrane = datumOdbrane; }
	//operator dodjele je vec implementiran za ovu klasu, nema potrebe za izmjenom
	ZavrsniRad& operator=(const ZavrsniRad& org) {
		if (this != &org) {
			delete[] _tema;
			_tema =AlocirajNizKaraktera(org._tema);
			_datumOdbrane = org._datumOdbrane;
			_poglavljaRada = org._poglavljaRada;
			_konacnaOcjena = org._konacnaOcjena;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& COUT, ZavrsniRad& obj) {
		COUT << "Tema rada: " << obj._tema << endl;
		COUT << "Sadrzaj: " <<endl;
		for (size_t i = 0; i < obj._poglavljaRada.size(); i++)
			COUT << obj._poglavljaRada[i] << endl;
		COUT << "Datum odbrane rada: " << obj._datumOdbrane << endl << " Ocjena: " << obj._konacnaOcjena << endl;
		return COUT;
	}

	//završiti implementaciju funkcije
	/*u zavrsni rad dodaje novo poglavlje i njegov sadrzaj. ukoliko poglavlje vec postoji u zavrsnom radu, funkcija tom poglavlju treba dodati novi sadrzaj i pri tome zadrzi
	postojeci (izmedju postojeceg i novog sadrzaja se dodaje prazan prostor). u slucaju da poglavlje ne postoji, ono se dodaje zajedno sa sadrzaje*/
	void DodajPoglavlje(const char* naslov, const char* sadrzaj)
	{
		
	}

	//zavrsiti implementaciju funkcije
	/*funkcija OcijeniPoglavlje, na osnovu naziva poglavlja, dodjeljuje ocjenu poglavlju te ukoliko je ocjena pozitivna (6 - 10) onda poglavlje oznacava prihvacenim.
	U slucaju da ocjena nije validna ili poglavlje ne postoji, funkcija baca izuzetak sa odgovarajucom porukom*/
	void OcijeniPoglavlje(const char* naziv, int ocjena)
	{
		
	}

	//potrebno je implementirati opertor usporedbe (==) za klasu ZavrsniRad, porediti samo naziv teme
	bool operator==(ZavrsniRad zr)
	{
	}

	//potrebno je izracunati prosjecnu ocjenu za sva poglavlja rada koja se nalaze u vektoru _poglavljaRada i vratiti tu vrijednost iz funkcije
	float prosjecnaOcjena()
	{
		
	}
	//implementirati setersku funkciju za atribut _konacnaOcjena
	void SetKonacnaOcjena(float o)
	{
	}
};

	class Mentor {
		char* _imePrezime;
		//Parametar string predstavlja broj indeksa studenta koji prijavljuje zavrsni rad kod odredjenog Mentora
		Kolekcija<const char*, ZavrsniRad> _teme;
	public:
		//zavrsiti implementaciju copy ctor-a
		Mentor(const Mentor& obj) : _teme(obj._teme)
		{
		}
		//implementirati user-def. ctor, dodijeliti samo odgovarajucu vrijednost atributu _imePrezime
		Mentor(const char* imePrezime)
		{
		}
		//zavrsiti implementaciju operatora dodjele
		Mentor& operator=(const Mentor& obj)
		{
			return *this;
		}

		~Mentor() {
			delete[] _imePrezime; _imePrezime = nullptr;
		}
		Kolekcija<const char*, ZavrsniRad>& GetTeme() { return _teme; };
		char* GetImePrezime() { return _imePrezime; }
		void Info() {
			cout << _imePrezime << endl << _teme << endl;
		}

		/*funkcija DodajZavrsniRad ima zadatak da odredjenom Mentoru dodijeli mentorstvo na zavrsnom radu. zavrsni rad se dodaje studentu sa brojem indeksa proslijedjenim kao
		prvi parametar. sprijeciti dodavanje zavrsnih radova sa istom temom*/
		bool DodajZavrsniRad(const char* brojIndeksa, ZavrsniRad zr)
		{
			return false;
		}
};

int main() {
	cout << crt << "UPLOAD RADA OBAVEZNO IZVRSITI U ODGOVARAJUCI FOLDER NA FTP SERVERU" << endl;
	cout << "U slucaju da je Upload folder prazan pritisnite tipku F5" << crt;

	const int max = 4;
	Mentor* mentori[max];

	mentori[0] = new Mentor("Armina Hubana");
	mentori[1] = new Mentor("Zanin Vejzovic");
	mentori[2] = new Mentor("Jasmin Azemovic");
	mentori[3] = new Mentor("Emina Junuz");
	//parametri: naziv zavrsnog rada
	ZavrsniRad multimedijalni("Multimedijalni informacijski sistem za visoko - obrazovnu ustanovu");
	ZavrsniRad podrsa_operaterima("Sistem za podršku rada kablovskog operatera");
	ZavrsniRad analiza_sigurnosti("Prakticna analiza sigurnosti beži?nih ra?unarskih mreža");
	ZavrsniRad kriptografija("Primjena teorije informacija u procesu generisanja kriptografskih klju?eva");

	/*u zavrsni rad dodaje novo poglavlje i njegov sadrzaj. ukoliko poglavlje vec postoji u zavrsnom radu, funkcija tom poglavlju treba dodati novi sadrzaj i pri tome zadrzi
	postojeci (izmedju postojeceg i novog sadrzaja se dodaje prazan prostor). u slucaju da poglavlje ne postoji, ono se dodaje zajedno sa sadrzaje*/
	//parametri: nazivPoglavlja, sadrzajPoglavlja
	multimedijalni.DodajPoglavlje("Uvod", "U ovom poglavlju ce biti rijeci");
	multimedijalni.DodajPoglavlje("Uvod", "o multimedijalnim sistemima koji se danas koriste");
	multimedijalni.DodajPoglavlje("Uvod", "u savremenom poslovanju");
	multimedijalni.DodajPoglavlje("Vrste multimedijalnih sistema", "Danas se moze govoriti o nekoliko vrsta multimedijalnih sistema, a neke od najznacajnijih su ...");
	multimedijalni.DodajPoglavlje("Teorija multimedije", "Sadrzaj koji bi trebao stajati na pocetku treceg poglavlja zavrsnog rada o multimediji studenta IB130011");
	multimedijalni.DodajPoglavlje("Zakljucak", "U ovom radu su predstavljeni osnovni koncepti i prakticna primjena...");

	try {
		/*funkcija OcijeniPoglavlje, na osnovu naziva poglavlja, dodjeljuje ocjenu poglavlju te ukoliko je ocjena pozitivna (6 - 10) onda poglavlje oznacava prihvacenim.
		U slucaju da ocjena nije validna ili poglavlje ne postoji, funkcija baca izuzetak sa odgovarajucom porukom*/
		//parametri:nazivPoglavlja, ocjena

		multimedijalni.OcijeniPoglavlje("Uvod", 8);
		multimedijalni.OcijeniPoglavlje("Vrste multimedijalnih sistema", 8);
		multimedijalni.OcijeniPoglavlje("Teorija multimedije", 9);
		multimedijalni.OcijeniPoglavlje("Zakljucak", 7);
		multimedijalni.OcijeniPoglavlje("Naziv poglavlja ne postoji", 8);
	}
	catch (exception& err) {
		cout << "Greska -> " << err.what() << endl;
	}

	/*funkcija DodajZavrsniRad ima zadatak da odredjenom Mentoru dodijeli mentorstvo na zavrsnom radu. zavrsni rad se dodaje studentu sa brojem indeksa proslijedjenim kao 
	prvi parametar. sprijeciti dodavanje zavrsnih radova sa istom temom*/
	//parametri:brojIndeksa, zavrsniRad
	if (mentori[0]->DodajZavrsniRad("IB130011", multimedijalni))
		cout << "Zavrsni rad uspjesno dodat!" << endl;
	if (mentori[0]->DodajZavrsniRad("IB120051", podrsa_operaterima))
		cout << "Zavrsni rad uspjesno dodat!" << endl;
	if (!mentori[0]->DodajZavrsniRad("IB120056", podrsa_operaterima))//dupliranje rada
		cout << "Zavrsni rad nije dodat!" << endl;
	if (!mentori[0]->DodajZavrsniRad("IB120051", kriptografija)) //studentu vec dodijeljen rad
		cout << "Zavrsni rad nije dodat!" << endl;
	if (mentori[1]->DodajZavrsniRad("IB140102", analiza_sigurnosti))
		cout << "Zavrsni rad uspjesno dodat!" << endl;
	if (mentori[2]->DodajZavrsniRad("IB140002", kriptografija))
		cout << "Zavrsni rad uspjesno dodat!" << endl;

	for (int i = 0; i < max; i++) {
		delete mentori[i];
		mentori[i] = nullptr;
	}
	system("pause>0");
	return 0;
}
