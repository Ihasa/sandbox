using System;
using System.IO;
using NPOI.SS.UserModel;
using NPOI.HSSF.UserModel;
using NPOI.XSSF.UserModel;

//リファレンスはここ(POI本家) https://poi.apache.org/apidocs/5.0/org/apache/poi/hssf/usermodel/HSSFWorkbook.html

namespace hoge{
    public class ExBook{
        private IWorkbook workBook;
        private string filePath;
        private ExBook(IWorkbook iniWB, string iniPath){
            workBook = iniWB;
            filePath = iniPath;
        }
        public ExBook(string filePath){
            //引数に指定された名前のブックが開きたい
        }

        public void AddSheet(string sheetName){
            workBook.CreateSheet( sheetName );
        }

        public void SaveBook(){
            using( var fs = new FileStream( filePath, FileMode.Create ) ) {
                workBook.Write(fs);
            }
        }

        public static ExBook CreateNew(string filePath){
            IWorkbook book;
            var extension = Path.GetExtension( filePath );

            // HSSF => Microsoft Excel(xls形式)(excel 97-2003)
            // XSSF => Office Open XML Workbook形式(xlsx形式)(excel 2007以降)
            if( extension == ".xls" ) {
                book = new HSSFWorkbook();
            }
            else if( extension == ".xlsx" ) {
                book = new XSSFWorkbook();
            }
            else {
                throw new ApplicationException( "CreateNewBook: invalid extension" );
            }

            return new ExBook(book, filePath);
        }
    }
}