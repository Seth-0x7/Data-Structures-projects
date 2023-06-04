CXX=g++ 
C11=--std=c++11
SRC_INTER= $(wildcard *_intervalle.cpp)
SRC_ARBRE= $(wildcard *_intervalleAVL.cpp)
EXEC_INTER= $(wildcard *_intervalle)
EXEC_ARBRE= $(wildcard *_intervalleAVL)

build: $(SRC_INTER) $(SRC_ARBRE) tp2.cpp
	$(CXX) $(C11) 01_intervalle.cpp -o 01_intervalle
	$(CXX) $(C11) 02_intervalle.cpp -o 02_intervalle
	$(CXX) $(C11) 03_intervalle.cpp -o 03_intervalle
	$(CXX) $(C11) 04_intervalle.cpp -o 04_intervalle
	$(CXX) $(C11) 05_intervalle.cpp -o 05_intervalle
	$(CXX) $(C11) 01_intervalleAVL.cpp -o 01_intervalleAVL
	$(CXX) $(C11) 02_intervalleAVL.cpp -o 02_intervalleAVL
	$(CXX) $(C11) 03_intervalleAVL.cpp -o 03_intervalleAVL
	$(CXX) $(C11) 04_intervalleAVL.cpp -o 04_intervalleAVL
	$(CXX) $(C11) 05_intervalleAVL.cpp -o 05_intervalleAVL
	$(CXX) $(C11) 06_intervalleAVL.cpp -o 06_intervalleAVL
	$(CXX) $(C11) 07_intervalleAVL.cpp -o 07_intervalleAVL
	$(CXX) $(C11) 08_intervalleAVL.cpp -o 08_intervalleAVL
	$(CXX) $(C11) 09_intervalleAVL.cpp -o 09_intervalleAVL
	$(CXX) $(C11) tp2.cpp -o tp2

intervalle: $(EXEC_INTER)
	./01_intervalle
	./02_intervalle
	./03_intervalle
	./04_intervalle
	./05_intervalle

intervalleAVL: $(EXEC_ARBRE)
	./01_intervalleAVL
	./02_intervalleAVL
	./03_intervalleAVL
	./04_intervalleAVL
	./05_intervalleAVL
	./06_intervalleAVL
	./07_intervalleAVL
	./08_intervalleAVL
	./09_intervalleAVL

tp: tp2
	./tp2 -a 19.5 1.5 < taches_exemple
	./tp2 -a 1000 0 < taches_1
	./tp2 -a 50000 49999 < taches_2
	./tp2 -c "[18,21]" 6 "[15,17]" 5 "[17,20]" 6 "[27,28]" 0 < taches_exemple
	./tp2	-c "[9,10]" 4 "[16,17]" 4 "[73,74]" 4 "[123,124]" 4 "[176,177]" 4 "[280,281]" 4 < taches_3
	./tp2	-c "[1511,1512]" 4 "[2023,2024]" 4 "[3361,3362]" 4 "[4433,4434]" 4 "[5473,5474]" 4 "[6941,6942]" 4 < taches_3
	./tp2	-c "[7247,7248]" 4 "[7530,7531]" 4 "[8239,8240]" 4 "[9145,9146]" 4 < taches_3
	./tp2	-c "[0,1]" 1 "[1,2]" 2 "[0,4]" 4 "[10000,10001]" 3 "[10002,10003]" 1 < taches_3

full: intervalle intervalleAVL tp

clean:
	rm $(EXEC_INTER)
	rm $(EXEC_ARBRE)
	rm tp2
