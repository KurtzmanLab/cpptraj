#ifndef INC_CIFFILE_H
#define INC_CIFFILE_H
#include "Atom.h"
#include "BufferedLine.h"
#include <map>
/// Used to access CIF files
class CIFfile {
  public:
    CIFfile() {}
    int Read(std::string const&);
  private:

    BufferedLine file_;
    enum mode { UNKNOWN = 0, SERIAL, LOOP };
    typedef std::vector<std::string> Sarray;

    class DataBlock;
    typedef std::map<std::string, DataBlock> CIF_DataType;
};

class CIFfile::DataBlock {
  public:
    DataBlock() {}
    std::string const& Header() const { return dataHeader_; }
    int AddHeader(std::string const&);
    int AddSerialDataRecord(const char*, BufferedLine&);
    int AddLoopColumn(const char*);
    int AddLoopData(const char*, BufferedLine&);
    void ListData() const;
  private:
    static int ParseData(std::string const&, std::string&, std::string&);

    std::string dataHeader_; ///< The data header, e.g. '_atom_site'
    Sarray columnHeaders_;   ///< Column headers, e.g. 'label_atom_id'
    std::vector<Sarray> columnData_; ///< Array of column data, e.g.:
      /*
ATOM 1    N N    . SER A 1 1  ? -2.559 9.064   0.084   1.00 0.00 ? ? ? ? ? ? 1  SER A N    1
ATOM 2    C CA   . SER A 1 1  ? -3.245 8.118   0.982   1.00 0.00 ? ? ? ? ? ? 1  SER A CA   1
       */
};
#endif
