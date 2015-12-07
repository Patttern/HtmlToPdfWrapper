package net.patttern.classes;

import com.sun.jna.Structure;
import net.patttern.enums.PageSize;

/**
 * Created by ebabenko on 07.12.15.
 */
public class Size extends Structure {
/*
  Size();
  //! What size paper should we use
  QPrinter::PageSize pageSize;
  //!Height of the page
  UnitReal height;
  //!Width of the page
  UnitReal width;
*/
  public PageSize pageSize;
  public UnitReal height;
  public UnitReal width;

  public Size() {
  }
}
