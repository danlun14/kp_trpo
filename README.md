1)Функциональность проекта. Описание с точки зрения пользователя: какие задачи решает продукт, какие покрывает сценарии использования.

Производится проверка входных данных в зависимости от этапа разработки(описание в формате входных файлов) и считается количество элементов(слов). Входные данные берутся из файла, указанного пользователем(minimum: без аргументов коммандной строки, программа делает запрос на имя). Входной файл(расширение .txt) должен находиться в одной папке с исполняемым файлом. Также во время выподнения считывания данных с файла проверяется его наличие, при отсутствии выводится ошибка. После успешного выполнения программы, результат записываются в файл с именем sorted_<имя исходного файла>.txt в одну строчку 1 слово(каждая строка заканчивается на \n). Также если выходной файл существовал, то производится запрос на продолжение работы программы, чтобы пользователь мог проверить его содержимое.
 
2)Формат входных данных.



3)Интерфейс приложения. В каком режиме работает приложение (интерактивный или нет, фоновый процесс, сетевой сервис и т. д.). Какие элементы интерфейса предусмотрены, их поведение.



4)Если приложение принимает аргументы командной строки, то их формат и описание.



5)Если предполагается использовать чтение исходных данных извне программы: конфигурационного файла, базы данных, источников в Интернет и т.д., то необходимо описание формата / протокола взаимодействия.
