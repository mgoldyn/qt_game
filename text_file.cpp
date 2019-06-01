#include <QFile>
#include <QDir>
#include <QDebug>

void check_file()
{
  QFile file{"user_data.txt"};

  if(!file.exists())
    {
      qDebug() << file.fileName() << "does not exist";
    }
  if(file.open(QIODevice::ReadOnly | QIODevice::WriteOnly | QIODevice::Text))
    {
      QTextStream txt_stream(&file);

      qDebug() << "Writing to file";

      txt_stream << "first line\n";
      txt_stream << "second line\n";

      qDebug() <<"Reading from file";
      txt_stream.seek(0);
      while(!txt_stream.atEnd())
        {
          qDebug() << txt_stream.readLine();
        }
      file.close();
    }
  else
    {
    qDebug() << "Could not open the file";
    return;
    }
}
