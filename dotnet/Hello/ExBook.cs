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
        public ExBook(string iniFilePath){
            filePath = iniFilePath;
            //引数に指定された名前のブックが開く
            workBook = WorkbookFactory.Create(filePath);
        }

        public void AddSheet(string sheetName){
            workBook.CreateSheet( sheetName );
        }

        public ISheet GetSheet(string sheetName){
            return workBook.GetSheet(sheetName);
        }

        public ICellStyle GetStyle(){
            var style = workBook.CreateCellStyle();
            style.DataFormat = workBook.CreateDataFormat().GetFormat( "yyyy/mm/dd" );
            return style;
        }

        public void SaveBook(){
            SaveBookAs(filePath);
        }

        public void SaveBookAs(string path){
            try{
                using( var fs = new FileStream( path, FileMode.Create ) ) {
                    workBook.Write(fs);
                }
            } catch (Exception e){
                throw e;
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