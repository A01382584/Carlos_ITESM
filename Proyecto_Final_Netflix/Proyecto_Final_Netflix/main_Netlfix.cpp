#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Episodio.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Video.h"

using namespace std;

int main() {

	int opcion;
	cout << "C++flix" << endl;
	cout << endl;
	cout << "Bienvenido!!!" << endl;
	cout << endl;

	do {
		
		cout << "Seleccione una de las siguientes opciones.\n"
			<< "1.Cargar Archivo de datos.\n"
			<< "2. Mostrar los videos en general con una calificación arriba de 7.\n"
			<< "3. Mostrar los episodios con una calificacion arriba de 8.\n"
			<< "4. Mostrar las películas con una calificación arriba de 7.\n"
			<< "0. Salir\n";

		cout << endl;
		cin >> opcion;
		cout << endl;

		switch (opcion) {
		case 1:
			cout << "Caso 1" << endl;

			Video* arrVideos[10];
			void LeerPelicula(); {

				string ID, Nombre, Duracion, Genero, linea, dato, temporal;
				int Calificacion = 0;
				int	contador = 0;

				ifstream Lectura;

				Lectura.open("PeliculasconGeneroyCalif.csv");
				while (getline(Lectura, linea)) {

					stringstream Registro(linea);
					int columna = 0;

					while (getline(Registro, dato, ',')) {

						switch (columna++) {
						case 0:
							ID = dato;
							break;

						case 1:
							Nombre = dato;
							break;

						case 2:
							Duracion = dato;
							break;

						case 3:
							Genero = dato;
							break;

						case 4:
							temporal = dato;
							Calificacion = atoi(temporal.c_str());
							break;
						}
						arrVideos[contador] = new Pelicula(ID, Nombre, Duracion, Genero, Calificacion);
					}
					contador++;
				}

				for (int x = 0; x < contador; x++) {

					Video* current = arrVideos[x];
					current->GetMuestra();

				}
				Lectura.close();
			}

			cout << endl;

			Video* arrVideos2[5];
			void LeerSerie(); {

				string ID, Nombre, Duracion, Genero, linea, dato, temporal;
				int Calificacion = 0;
				int temporada = 0;
				int	contador = 0;

				ifstream Lectura2;

				Lectura2.open("SeriesconCalifyDuracion.csv");
				while (getline(Lectura2, linea)) {

					stringstream Registro2(linea);
					int columna = 0;

					while (getline(Registro2, dato, ',')) {

						switch (columna++) {
						case 0:
							ID = dato;
							break;

						case 1:
							Nombre = dato;
							break;

						case 2:
							Duracion = dato;
							break;

						case 3:
							Genero = dato;
							break;

						case 4:
							temporal = dato;
							Calificacion = atoi(temporal.c_str());
							break;

						case 5:
							temporal = dato;
							temporada = atoi(temporal.c_str());
							break;
						}
						arrVideos2[contador] = new Serie(ID, Nombre, Duracion, Genero, Calificacion, temporada);

					}
					contador++;
				}
				for (int x = 0; x < contador; x++) {

					Video* current = arrVideos2[x];
					current->GetMuestra();

				}
				Lectura2.close();
			}

			cout << endl;

			Episodio* arrVideos3[200];
			void LeerEpisodio(); {

				string ID, ID_Episodio, Nombre, Duracion, Genero, linea, dato, temporal;
				int Calificacion = 0;
				int temporada = 0;
				int	contador = 0;

				ifstream Lectura3;

				Lectura3.open("EpisodioconGenero.csv");
				while (getline(Lectura3, linea)) {

					stringstream Registro2(linea);
					int columna = 0;

					while (getline(Registro2, dato, ',')) {

						switch (columna++) {
						case 0:
							ID = dato;
							break;

						case 1:
							ID_Episodio = dato;
							break;

						case 2:
							Nombre = dato;
							break;

						case 3:
							Duracion = dato;
							break;

						case 4:
							temporal = dato;
							Calificacion = atoi(temporal.c_str());
							break;

						case 5:
							temporal = dato;
							temporada = atoi(temporal.c_str());
							break;

						case 6:
							Genero = dato;
							break;
						}
						arrVideos3[contador] = new Episodio(ID,ID_Episodio, Nombre, Duracion, Calificacion, temporada, Genero);

					}
					contador++;
				}
				for (int x = 0; x < contador; x++) {

					Episodio* current = arrVideos3[x];
					current->getDetalles();

				}
				Lectura3.close();
			}

			cout << endl;
			break;

		case 2:
			cout << "Caso 2" << endl;

			Video* arrVideos4[10];
			void LeerPeliculaFiltrado(); {

				string ID, Nombre, Duracion, Genero, linea, dato, temporal;
				int Calificacion = 0;
				int	contador = 0;

				ifstream Lectura;

				Lectura.open("PeliculasconGeneroyCalif.csv");
				while (getline(Lectura, linea)) {

					stringstream Registro(linea);
					int columna = 0;

					while (getline(Registro, dato, ',')) {

						switch (columna++) {
						case 0:
							ID = dato;
							break;

						case 1:
							Nombre = dato;
							break;

						case 2:
							Duracion = dato;
							break;

						case 3:
							Genero = dato;
							break;

						case 4:
							temporal = dato;
							Calificacion = atoi(temporal.c_str());
							break;
						}

						arrVideos4[contador] = new Pelicula(ID, Nombre, Duracion, Genero, Calificacion);
					}
					contador++;
				}

				for (int x = 0; x < contador; x++) {

					Video* current = arrVideos4[x];
					current->GetFiltrado();

				}
				Lectura.close();
			}

			cout << endl;

			Episodio* arrVideos5[200];
			void LeerEpisodio(); {

				string ID, ID_Episodio, Nombre, Duracion, Genero, linea, dato, temporal;
				int Calificacion = 0;
				int temporada = 0;
				int	contador = 0;

				ifstream Lectura3;

				Lectura3.open("EpisodioconGenero.csv");
				while (getline(Lectura3, linea)) {

					stringstream Registro2(linea);
					int columna = 0;

					while (getline(Registro2, dato, ',')) {

						switch (columna++) {
						case 0:
							ID = dato;
							break;

						case 1:
							ID_Episodio = dato;
							break;

						case 2:
							Nombre = dato;
							break;

						case 3:
							Duracion = dato;
							break;

						case 4:
							temporal = dato;
							Calificacion = atoi(temporal.c_str());
							break;

						case 5:
							temporal = dato;
							temporada = atoi(temporal.c_str());
							break;

						case 6:
							Genero = dato;
							break;
						}
						arrVideos5[contador] = new Episodio(ID, ID_Episodio, Nombre, Duracion, Calificacion, temporada, Genero);

					}
					contador++;
				}
				for (int x = 0; x < contador; x++) {

					Episodio* current = arrVideos5[x];
					current->getFiltrado();

				}
				Lectura3.close();
			}

			cout << endl;

			break;

		case 3:
			cout << "Caso 3" << endl;

			Episodio* arrVideos6[200];
			void LeerEpisodio(); {

				string ID, ID_Episodio, Nombre, Duracion, Genero, linea, dato, temporal;
				int Calificacion = 0;
				int temporada = 0;
				int	contador = 0;

				ifstream Lectura3;

				Lectura3.open("EpisodioconGenero.csv");
				while (getline(Lectura3, linea)) {

					stringstream Registro2(linea);
					int columna = 0;

					while (getline(Registro2, dato, ',')) {

						switch (columna++) {
						case 0:
							ID = dato;
							break;

						case 1:
							ID_Episodio = dato;
							break;

						case 2:
							Nombre = dato;
							break;

						case 3:
							Duracion = dato;
							break;

						case 4:
							temporal = dato;
							Calificacion = atoi(temporal.c_str());
							break;

						case 5:
							temporal = dato;
							temporada = atoi(temporal.c_str());
							break;

						case 6:
							Genero = dato;
							break;
						}
						arrVideos6[contador] = new Episodio(ID, ID_Episodio, Nombre, Duracion, Calificacion, temporada, Genero);

					}
					contador++;
				}
				for (int x = 0; x < contador; x++) {

					Episodio* current = arrVideos6[x];
					current->getFiltrado2();

				}
				Lectura3.close();
			}

			cout << endl;

			break;

		case 4:
			cout << "Caso 4" << endl;
			Video* arrVideos7[10];

			void LeerPeliculaFiltrado(); {

				string ID, Nombre, Duracion, Genero, linea, dato, temporal;
				int Calificacion = 0;
				int	contador = 0;

				ifstream Lectura;

				Lectura.open("PeliculasconGeneroyCalif.csv");
				while (getline(Lectura, linea)) {

					stringstream Registro(linea);
					int columna = 0;

					while (getline(Registro, dato, ',')) {

						switch (columna++) {
						case 0:
							ID = dato;
							break;

						case 1:
							Nombre = dato;
							break;

						case 2:
							Duracion = dato;
							break;

						case 3:
							Genero = dato;
							break;

						case 4:
							temporal = dato;
							Calificacion = atoi(temporal.c_str());
							break;
						}

						arrVideos7[contador] = new Pelicula(ID, Nombre, Duracion, Genero, Calificacion);
					}
					contador++;
				}

				for (int x = 0; x < contador; x++) {

					Video* current = arrVideos7[x];
					current->GetFiltrado();

				}
				Lectura.close();
			}

			cout << endl;

			break;

		case 0:
			cout << "Muchas gracias por su visita" << endl;
			break;

		default:
			cout << "Seleccione una opcion del menu, porfavor. " << endl;
			cout << endl;

		};

	} while (opcion != 0);
	return 0;
};