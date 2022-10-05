import { Component, ViewChild } from '@angular/core';
import { MatGridList } from '@angular/material/grid-list';
@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.sass']
})
export class AppComponent {

  title = 'Grid'
  @ViewChild(MatGridList) grid: MatGridList | undefined

  dimension = 0
  cells: any[] = []

  initialCellId = 0
  finalCellId = 0

  appState: 'point-selection' | 'block-selection' | 'result' = 'point-selection'

  constructor() {
    this.renderCells(3);
  }

  renderCells(dimension: number): void {
    this.dimension = dimension
    this.cells = Array(dimension**2)
    .fill(0)
    .map((v, i) => ({
      id: i+1,
      status: 'blank'
    }))
  }

  onCellClick(cell: any) {
    let { status } = cell
    cell.status = cell.status == 'blocked' ? 'blank' : 'blocked'
  }

}

// TODO: Grid gutter expansion/retractoin animation for loading